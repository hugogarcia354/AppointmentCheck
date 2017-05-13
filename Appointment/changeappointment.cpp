#include "changeappointment.h"
#include "ui_changeappointment.h"

ChangeAppointment::ChangeAppointment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeAppointment)
{
    ui->setupUi(this);

    AppointmentCheck list;
    list.connOpen();
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery(list.mydb);

    qry->prepare("select firstName, lastName from contact");

    qry->exec();
    modal->setQuery(*qry);

    ui->contactList->setModel(modal);
    ui->userBox->setCurrentText(userplus);

    list.connClose();
    list.close();
    updateApp();
    ui->newContact->setText(ui->contactList->currentText());
    ui->calendarWidget->setMinimumDate(QDate::currentDate());
    if(dayof){
    ui->calendarWidget->setFirstDayOfWeek(day);
    }
    ui->calendarWidget->setStyleSheet(color);
    ui->calendarWidget->setGridVisible(grid);
}

ChangeAppointment::~ChangeAppointment()
{
    delete ui;
}

void ChangeAppointment::on_close_clicked()
{
    this->close();
}

void ChangeAppointment::updateApp(){
    AppointmentCheck w;
    w.connOpen();
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery(w.mydb);

    if(username == "Admin"){
         qry->prepare("select username,contact,DateTime from appointment");
    }
    else
    qry->prepare("select contact,DateTime from appointment where username='"+userplus+"'");


    qry->exec();
    model->setQuery(*qry);
    ui->AppointmentView->setModel(model);

    QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
    m->setDynamicSortFilter(true);
    m->setSourceModel(model);
    ui->AppointmentView->setModel(m);
    ui->AppointmentView->setSortingEnabled(true);

    if(username=="Admin"){
        ui->userBox->setEnabled(true);
        qry->prepare("select username from account");
        qry->exec();
        QSqlQueryModel * modal = new QSqlQueryModel();
        modal->setQuery(*qry);
        ui->userBox->setModel(modal);
    }
    w.connClose();
    w.close();
}

void ChangeAppointment::setUser(QString user){
    userplus = user;
    username = user;
}

void ChangeAppointment::on_AppointmentView_clicked(const QModelIndex &index)
{
    int row = index.row();
    QString contact;
    QString dateTime;
    QString user;
    if(username =="Admin"){
        user = index.sibling(row, 0).data().toString();
        contact = index.sibling(row, 1).data().toString();
        dateTime = index.sibling(row, 2).data().toString();
        ui->currentUser->setText(user);
    }
    else{
        contact = index.sibling(row, 0).data().toString();
        dateTime = index.sibling(row, 1).data().toString();
    }
    ui->currentContact->setText(contact);
    ui->currentDate->setText(dateTime);
    ui->update->setEnabled(true);


}

void ChangeAppointment::on_update_clicked()
{
    QString currentContact = ui->currentContact->text();
    QString currentDate = ui->currentDate->text();
    QString newContact = ui->newContact->text();
    QString newDate = ui->newDate->text();
    AppointmentCheck conn;
    conn.connOpen();
    QSqlQuery qry;


    QSqlQueryModel * model = new QSqlQueryModel();//create model for tableview
    QSqlQuery *qry2 = new QSqlQuery(conn.mydb);
    QDate day = ui->dateEdit->date();
    int dayOfWeek = day.dayOfWeek();
    QString checkDay;
    switch(dayOfWeek){
    case 1:
        checkDay = "Monday";
        break;
    case 2:
        checkDay = "Tuesday";
        break;
    case 3:
        checkDay = "Wednesday";
        break;
    case 4:
        checkDay = "Thursday";
        break;
    case 5:
        checkDay = "Friday";
        break;
    case 6:
        checkDay = "Saturday";
        break;
    case 7:
        checkDay = "Sunday";
        break;
    }

    if(qry.exec("select * from account where username = '"+username+"' and "+checkDay+" is not null")){
        int count =0;
        while(qry.next()){
            count++; //checks if user has schedule for monday
        }
        if (count>0){

            qry2->prepare("select "+checkDay+" from account where username='"+username+"'");

            qry2->exec();
            model->setQuery(*qry2);
            QTableView *table = new QTableView();
            table->setModel(model); //set appointment view from query model

            QString Time = table->model()->data(table->model()->index(0,0)).toString();


            QStringList timePieces = Time.split("-"); //split up to get date only


            QTime time1 = QTime::fromString(timePieces.value(0),"hh:mm ap");
            QTime time2 = QTime::fromString(timePieces.value(1),"hh:mm ap");
            QTime main = ui->timeEdit->time();

            if(main>=time1 && main <=time2){

    if(ui->userBox->isEnabled()){
        QString currentUser = ui->currentUser->text();
        QString newUser = ui->newUser->text();
        qry.prepare("UPDATE appointment SET username = '"+newUser+"',contact = '"+newContact+"', DateTime ='"+newDate+"' WHERE username = '"+currentUser+"' AND contact = '"+currentContact+"' AND DateTime = '"+currentDate+"'");

    }
    else
    qry.prepare("UPDATE appointment SET contact = '"+newContact+"', DateTime ='"+newDate+"' WHERE username = '"+userplus+"' AND contact = '"+currentContact+"' AND DateTime = '"+currentDate+"'");

    if(qry.exec()){
        QMessageBox mess;
        mess.setText("Appointment Updated");
        mess.exec();
    }
    else{
        QMessageBox mess;
        mess.setText("Failed to Update");
        mess.exec();
    }
            }
            else{
                QMessageBox mess;
                mess.setText("Appointment not available during chosen hours.\nAppointment not Created.");
                mess.exec();
            }
        }
        else{
            QMessageBox mess;
            mess.setText("Appointment not available during chosen hours.\nAppointment not Created.");
            mess.exec();
        }
    }



    conn.connClose();
    updateApp();

}





void ChangeAppointment::on_contactList_activated(const QString &arg1)
{
    ui->newContact->setText(arg1);

}



void ChangeAppointment::on_timeEdit_timeChanged(const QTime &time)
{
    QString date = ui->dateEdit->date().toString("MM-dd-yyyy ");
    QString ntime = ui->timeEdit->time().toString("hh:mm ap");
    QString dateTime = date+ntime;
    ui->newDate->setText(dateTime);
}

void ChangeAppointment::on_dateEdit_dateChanged(const QDate &date)
{
    QString ndate = ui->dateEdit->date().toString("MM-dd-yyyy ");
    QString ntime = ui->timeEdit->time().toString("hh:mm ap");
    QString dateTime = ndate+ntime;
    ui->newDate->setText(dateTime);
}

void ChangeAppointment::on_userBox_activated(const QString &arg1)
{
    ui->newUser->setText(arg1);
}
