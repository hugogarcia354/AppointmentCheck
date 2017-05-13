#include "availability.h"
#include "ui_availability.h"

Availability::Availability(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Availability)
{

    ui->setupUi(this);

}

Availability::~Availability()
{
    delete ui;
}

void Availability::on_MondayBox_toggled(bool checked)
{
    ui->timeEdit->setEnabled(checked);
    ui->timeEdit_2->setEnabled(checked);
}

void Availability::on_SundayBox_toggled(bool checked)
{
    ui->timeEdit_13->setEnabled(checked);
    ui->timeEdit_14->setEnabled(checked);
}

void Availability::on_TuesdayBox_toggled(bool checked)
{
    ui->timeEdit_3->setEnabled(checked);
    ui->timeEdit_4->setEnabled(checked);
}

void Availability::on_WednesdayBox_toggled(bool checked)
{
    ui->timeEdit_5->setEnabled(checked);
    ui->timeEdit_6->setEnabled(checked);
}

void Availability::on_ThursdayBox_toggled(bool checked)
{
    ui->timeEdit_7->setEnabled(checked);
    ui->timeEdit_8->setEnabled(checked);
}

void Availability::on_FridayBox_toggled(bool checked)
{
    ui->timeEdit_9->setEnabled(checked);
    ui->timeEdit_10->setEnabled(checked);
}

void Availability::on_SaturdayBox_toggled(bool checked)
{
    ui->timeEdit_11->setEnabled(checked);
    ui->timeEdit_12->setEnabled(checked);
}

void Availability::on_buttonBox_accepted()
{
    AppointmentCheck list;
    list.connOpen();
    bool success[7] = {0,0,0,0,0,0,0};
    QSqlQuery * query = new QSqlQuery(list.mydb);
    if(ui->MondayBox->isChecked()){
         QString start = ui->timeEdit->time().toString("hh:mm ap");
         QString end = ui->timeEdit_2->time().toString("hh:mm ap");
         QString StartEnd = start+"-"+end;
         query->prepare("UPDATE account SET Monday = '"+StartEnd+"' WHERE username = '"+username+"'");
         if(query->exec())
             success[0]=1;
    }
    else{
        query->prepare("UPDATE account SET Monday = NULL WHERE username = '"+username+"'");
        if(query->exec())
            success[0]=1;
    }

    if(ui->TuesdayBox->isChecked()){
        QString start = ui->timeEdit_3->time().toString("hh:mm ap");
        QString end = ui->timeEdit_4->time().toString("hh:mm ap");
        QString StartEnd = start+"-"+end;
        query->prepare("UPDATE account SET Tuesday = '"+StartEnd+"' WHERE username = '"+username+"'");
        if(query->exec())
            success[1]=1;
    }
    else{
        query->prepare("UPDATE account SET Tuesday = NULL WHERE username = '"+username+"'");
        if(query->exec())
            success[1]=1;
    }

    if(ui->WednesdayBox->isChecked()){
        QString start = ui->timeEdit_5->time().toString("hh:mm ap");
        QString end = ui->timeEdit_6->time().toString("hh:mm ap");
        QString StartEnd = start+"-"+end;
        query->prepare("UPDATE account SET Wednesday = '"+StartEnd+"' WHERE username = '"+username+"'");
        if(query->exec())
            success[2]=1;
    }
    else{
        query->prepare("UPDATE account SET Wednesday = NULL WHERE username = '"+username+"'");
        if(query->exec())
            success[2]=1;
    }

    if(ui->ThursdayBox->isChecked()){
        QString start = ui->timeEdit_7->time().toString("hh:mm ap");
        QString end = ui->timeEdit_8->time().toString("hh:mm ap");
        QString StartEnd = start+"-"+end;
        query->prepare("UPDATE account SET Thursday = '"+StartEnd+"' WHERE username = '"+username+"'");
        if(query->exec())
            success[3]=1;
    }
    else{
        query->prepare("UPDATE account SET Thursday = NULL WHERE username = '"+username+"'");
        if(query->exec())
            success[3]=1;
    }

    if(ui->FridayBox->isChecked()){
        QString start = ui->timeEdit_9->time().toString("hh:mm ap");
        QString end = ui->timeEdit_10->time().toString("hh:mm ap");
        QString StartEnd = start+"-"+end;
        query->prepare("UPDATE account SET Friday = '"+StartEnd+"' WHERE username = '"+username+"'");
        if(query->exec())
            success[4]=1;
    }
    else{
        query->prepare("UPDATE account SET Friday = NULL WHERE username = '"+username+"'");
        if(query->exec())
            success[4]=1;
    }

    if(ui->SaturdayBox->isChecked()){
        QString start = ui->timeEdit_11->time().toString("hh:mm ap");
        QString end = ui->timeEdit_12->time().toString("hh:mm ap");
        QString StartEnd = start+"-"+end;
        query->prepare("UPDATE account SET Saturday = '"+StartEnd+"' WHERE username = '"+username+"'");
        if(query->exec())
            success[5]=1;
    }
    else{
        query->prepare("UPDATE account SET Saturday = NULL WHERE username = '"+username+"'");
        if(query->exec())
            success[5]=1;
    }

    if(ui->SundayBox->isChecked()){
        QString start = ui->timeEdit_13->time().toString("hh:mm ap");
        QString end = ui->timeEdit_14->time().toString("hh:mm ap");
        QString StartEnd = start+"-"+end;
        query->prepare("UPDATE account SET Sunday = '"+StartEnd+"' WHERE username = '"+username+"'");
        if(query->exec())
            success[6]=1;
    }
    else{
        query->prepare("UPDATE account SET Sunday =NULL WHERE username = '"+username+"'");
        if(query->exec())
            success[6]=1;
    }
}
void Availability::update(){
    AppointmentCheck list;
    list.connOpen();
    QSqlQueryModel * model = new QSqlQueryModel();//create model for tableview
    QSqlQuery *qry = new QSqlQuery(list.mydb);
    QSqlQuery *qry2 = new QSqlQuery(list.mydb);
    qry2->prepare("select Monday,Tuesday,Wednesday,Thursday,Friday, Saturday,Sunday from account where username='"+username+"'");

    qry2->exec();
    model->setQuery(*qry2);
    QTableView *table = new QTableView();
    table->setModel(model); //set appointment view from query model


    if(qry->exec("select * from account where username = '"+username+"' and Monday is not null")){
        int count =0;
        while(qry->next()){
            count++; //checks if user has schedule for monday
        }
        if (count>0){
             ui->MondayBox->setChecked(1);

             QString Time = table->model()->data(table->model()->index(0,0)).toString();


             QStringList timePieces = Time.split("-"); //split up to get date only

             QTime time1 = QTime::fromString(timePieces.value(0),"hh:mm ap");
             QTime time2 = QTime::fromString(timePieces.value(1),"hh:mm ap");
             ui->timeEdit->setTime(time1);
             ui->timeEdit_2->setTime(time2);

        }
    }


    if(qry->exec("select * from account where username = '"+username+"' and Tuesday is not null")){
        int count =0;
        while(qry->next()){
            count++; //checks if user has schedule for monday
        }
        if (count>0){
             ui->TuesdayBox->setChecked(1);

             QString Time = table->model()->data(table->model()->index(0,1)).toString();


             QStringList timePieces = Time.split("-"); //split up to get date only

             QTime time1 = QTime::fromString(timePieces.value(0),"hh:mm ap");
             QTime time2 = QTime::fromString(timePieces.value(1),"hh:mm ap");
             ui->timeEdit_3->setTime(time1);
             ui->timeEdit_4->setTime(time2);

        }
    }


    if(qry->exec("select * from account where username = '"+username+"' and Wednesday is not null")){
        int count =0;
        while(qry->next()){
            count++; //checks if user has schedule for monday
        }
        if (count>0){
             ui->WednesdayBox->setChecked(1);

             QString Time = table->model()->data(table->model()->index(0,2)).toString();


             QStringList timePieces = Time.split("-"); //split up to get date only

             QTime time1 = QTime::fromString(timePieces.value(0),"hh:mm ap");
             QTime time2 = QTime::fromString(timePieces.value(1),"hh:mm ap");
             ui->timeEdit_5->setTime(time1);
             ui->timeEdit_6->setTime(time2);

        }
    }


    if(qry->exec("select * from account where username = '"+username+"' and Thursday is not null")){
        int count =0;
        while(qry->next()){
            count++; //checks if user has schedule for monday
        }
        if (count>0){
             ui->ThursdayBox->setChecked(1);

             QString Time = table->model()->data(table->model()->index(0,3)).toString();


             QStringList timePieces = Time.split("-"); //split up to get date only

             QTime time1 = QTime::fromString(timePieces.value(0),"hh:mm ap");
             QTime time2 = QTime::fromString(timePieces.value(1),"hh:mm ap");
             ui->timeEdit_7->setTime(time1);
             ui->timeEdit_8->setTime(time2);

        }
    }


    if(qry->exec("select * from account where username = '"+username+"' and Friday is not null")){
        int count =0;
        while(qry->next()){
            count++; //checks if user has schedule for monday
        }
        if (count>0){
             ui->FridayBox->setChecked(1);

             QString Time = table->model()->data(table->model()->index(0,4)).toString();


             QStringList timePieces = Time.split("-"); //split up to get date only

             QTime time1 = QTime::fromString(timePieces.value(0),"hh:mm ap");
             QTime time2 = QTime::fromString(timePieces.value(1),"hh:mm ap");
             ui->timeEdit_9->setTime(time1);
             ui->timeEdit_10->setTime(time2);

        }
    }


    if(qry->exec("select * from account where username = '"+username+"' and Saturday is not null")){
        int count =0;
        while(qry->next()){
            count++; //checks if user has schedule for monday
        }
        if (count>0){
             ui->SaturdayBox->setChecked(1);

             QString Time = table->model()->data(table->model()->index(0,5)).toString();


             QStringList timePieces = Time.split("-"); //split up to get date only

             QTime time1 = QTime::fromString(timePieces.value(0),"hh:mm ap");
             QTime time2 = QTime::fromString(timePieces.value(1),"hh:mm ap");
             ui->timeEdit_11->setTime(time1);
             ui->timeEdit_12->setTime(time2);

        }
    }


    if(qry->exec("select * from account where username = '"+username+"' and Sunday is not null")){
        int count =0;
        while(qry->next()){
            count++; //checks if user has schedule for monday
        }
        if (count>0){
             ui->SundayBox->setChecked(1);

             QString Time = table->model()->data(table->model()->index(0,6)).toString();


             QStringList timePieces = Time.split("-"); //split up to get date only

             QTime time1 = QTime::fromString(timePieces.value(0),"hh:mm ap");
             QTime time2 = QTime::fromString(timePieces.value(1),"hh:mm ap");
             ui->timeEdit_13->setTime(time1);
             ui->timeEdit_14->setTime(time2);

        }
    }

    QSqlQueryModel * modal = new QSqlQueryModel();//create model for tableview


    if(username=="Admin"){
        ui->userBox->setEnabled(true);
        qry->prepare("select username from account");
        qry->exec();
        QSqlQueryModel * modal = new QSqlQueryModel();
        modal->setQuery(*qry);
        ui->userBox->setModel(modal);
    }
}




void Availability::on_userBox_activated(const QString &arg1)
{
    ui->MondayBox->setChecked(false);
    ui->TuesdayBox->setChecked(false);
    ui->WednesdayBox->setChecked(false);
    ui->ThursdayBox->setChecked(false);
    ui->FridayBox->setChecked(false);
    ui->SaturdayBox->setChecked(false);
    ui->SundayBox->setChecked(false);
    username= arg1;
    update();
}
