#include "listedrange.h"
#include "ui_listedrange.h"

listedRange::listedRange(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listedRange)
{
    ui->setupUi(this);
}

listedRange::~listedRange()
{
    delete ui;
}

void listedRange::on_StartDate_dateChanged(const QDate &date)
{
    QDate newDate = date.addDays(7);
    ui->EndDate->setDate(newDate);

    startTime = ui->StartDate->date();
    endTime = ui->EndDate->date();
}

void listedRange::on_EndDate_dateChanged(const QDate &date)
{
     QDate newDate = date.addDays(-7);
    ui->StartDate->setDate(newDate);
    startTime = ui->StartDate->date();
    endTime = ui->EndDate->date();
}

void listedRange::on_MonthStart_dateChanged(const QDate &date)
{
        QDate newDate = date.addDays(31);
        ui->MonthEnd->setDate(newDate);
        startTime = ui->MonthStart->date();
        endTime = ui->MonthEnd->date();
}

void listedRange::on_MonthEnd_dateChanged(const QDate &date)
{
        QDate newDate = date.addDays(-31);
        ui->MonthStart->setDate(newDate);
        startTime = ui->MonthStart->date();
        endTime = ui->MonthEnd->date();
}

void listedRange::on_WeekBox_toggled(bool checked)
{
    ui->StartDate->setEnabled(checked);
    ui->EndDate->setEnabled(checked);
    ui->MonthBox->setChecked(0);
    ui->AnyBox->setChecked(0);
    ui->pushButton->setEnabled(true);
}

void listedRange::on_MonthBox_toggled(bool checked)
{
    ui->MonthStart->setEnabled(checked);
    ui->MonthEnd->setEnabled(checked);
    ui->WeekBox->setChecked(0);
    ui->AnyBox->setChecked(0);
    ui->pushButton->setEnabled(true);
}

void listedRange::on_AnyBox_toggled(bool checked)
{
    ui->AnyStart->setEnabled(checked);
    ui->AnyEnd->setEnabled(checked);
    ui->MonthBox->setChecked(0);
    ui->WeekBox->setChecked(0);
    ui->pushButton->setEnabled(true);
}

void listedRange::on_pushButton_clicked()
{
    AppointmentCheck w;
    w.connOpen();

    QSqlQueryModel * model = new QSqlQueryModel();//create model for tableview
    QSqlQuery * qry = new QSqlQuery(w.mydb); //create query for database


   ui->AppointmentView->clearContents();
   if(username == "Admin"){
       qry->prepare("select username,contact,DateTime from appointment");

   }
   else
    qry->prepare("select contact,DateTime from appointment where username='"+username+"'");

  int count =0;
     if(qry->exec()){

            while(qry->next()){
                count++;
            }
    }

    model->setQuery(*qry);
    QTableView *table = new QTableView();
    table->setModel(model);
    QString contacts[20];
    QStringList dates[20];
    QString app[20];
    QString user[20];

    if(username == "Admin")
    for(int i = 0; i<count; i++){
        user[i] = table->model()->data(table->model()->index(i,0)).toString();
        app[i] = table->model()->data(table->model()->index(i,2)).toString();
        dates[i] = table->model()->data(table->model()->index(i,2)).toString().split(" ");
      contacts[i] = table->model()->data(table->model()->index(i,1)).toString();
    }
    else
        for(int i = 0; i<count; i++){
            app[i] = table->model()->data(table->model()->index(i,1)).toString();
            dates[i] = table->model()->data(table->model()->index(i,1)).toString().split(" ");
          contacts[i] = table->model()->data(table->model()->index(i,0)).toString();
        }

    QDate checkDate[20];
    for(int i = 0; i<count; i++){
        checkDate[i] = QDate::fromString(dates[i].value(0),"MM-dd-yyyy");

    }

    if(username == "Admin"){
        ui->AppointmentView->setRowCount(20);
        ui->AppointmentView->setColumnCount(3);
        QStringList m_TableHeader;
        m_TableHeader<<"User"<<"Contact"<<"Appointment";
        ui->AppointmentView->setHorizontalHeaderLabels(m_TableHeader);
        int j =0;
        for(int i =0; i<count;i++){
            if(checkDate[i]>= startTime && checkDate[i] <=endTime){
                ui->AppointmentView->setItem(j,0,new QTableWidgetItem(user[i]));
            ui->AppointmentView->setItem(j,1,new QTableWidgetItem(contacts[i]));
            ui->AppointmentView->setItem(j,2,new QTableWidgetItem(app[i]));
            j++;


            }
        ui->AppointmentView->setSortingEnabled(true);


    }
    }
    else{
    ui->AppointmentView->setRowCount(20);
    ui->AppointmentView->setColumnCount(2);
    QStringList m_TableHeader;
    m_TableHeader<<"Contact"<<"Appointment";
    ui->AppointmentView->setHorizontalHeaderLabels(m_TableHeader);
    int j =0;
    for(int i =0; i<count;i++){
        if(checkDate[i]>= startTime && checkDate[i] <=endTime){
        ui->AppointmentView->setItem(j,0,new QTableWidgetItem(contacts[i]));
        ui->AppointmentView->setItem(j,1,new QTableWidgetItem(app[i]));
        j++;


        }
    ui->AppointmentView->setSortingEnabled(true);
    }
    }

}



void listedRange::on_AnyStart_dateChanged(const QDate &date)
{
    startTime = ui->AnyStart->date();
    endTime = ui->AnyEnd->date();
}

void listedRange::on_AnyEnd_dateChanged(const QDate &date)
{
    startTime = ui->AnyStart->date();
    endTime = ui->AnyEnd->date();
}
