#include "createappointment.h"
#include "ui_createappointment.h"

createAppointment::createAppointment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createAppointment)
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
    list.connClose();
    list.close();
}



createAppointment::~createAppointment()
{
    delete ui;
}



void createAppointment::on_buttonBox_accepted()
{
    QString date = ui->dateEdit->date().toString("MM-dd-yyyy ");
    QString time = ui->timeEdit->time().toString("hh:mm ap");
    QString dateTime = date+time;
    QString contact = ui->contactList->currentText();
    AppointmentCheck conn;
    conn.connOpen();


    QSqlQueryModel * model = new QSqlQueryModel();//create model for tableview
    QSqlQuery *qry2 = new QSqlQuery(conn.mydb);


    QSqlQuery qry;
    if(ui->userBox->isEnabled()){
        username = ui->userBox->currentText();
    }
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


            qry.prepare("INSERT INTO appointment (username, contact, DateTime)VALUES ('"+username+"','"+contact+"','"+dateTime+"')");
            if(qry.exec()){
                 QMessageBox mess;
                 mess.setText("Appointment Created");
                 mess.exec();
             }
            else{
            QMessageBox mess;
            mess.setText("Failed to Create");
             mess.exec();
            }
                }
             else{
          QMessageBox mess;
          mess.setText("Appointment not during available hours.\nAppointment not Created.");
          mess.exec();
         }
            }
            else{
         QMessageBox mess;
         mess.setText("Appointment not during available hours.\nAppointment not Created.");
         mess.exec();
        }
     }


    conn.connClose();
}

void createAppointment::updateApp(){
    AppointmentCheck w;
    w.connOpen();
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery(w.mydb);
    if(username=="Admin"){
        ui->userBox->setEnabled(true);
        qry->prepare("select username from account");
        qry->exec();
        model->setQuery(*qry);
        ui->userBox->setModel(model);
    }
    ui->calendarWidget->setMinimumDate(QDate::currentDate());
    if(dayof){
    ui->calendarWidget->setFirstDayOfWeek(day);
    }
    ui->calendarWidget->setStyleSheet(color);
    ui->calendarWidget->setGridVisible(grid);
    w.connClose();
}
