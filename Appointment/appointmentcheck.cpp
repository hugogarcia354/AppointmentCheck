#include "appointmentcheck.h"
#include "ui_appointmentcheck.h"
#include <QMessageBox>

#define Path_to_DB "/home/hugo/Qt/AppointmentCheck.sqlite"
//#define Path_to_DB "C:/Users/Dragon/Documents/QT/AppointmentCheck.sqlite"

AppointmentCheck::AppointmentCheck(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AppointmentCheck)
{
    ui->setupUi(this);


}


AppointmentCheck::~AppointmentCheck()
{
    connClose();
    delete ui;
    this->done(2);


}

void AppointmentCheck::on_pushButton_clicked()
{
    username = ui->username->text();
    QString password = ui->password->text();
    open = connOpen();
        if(!open){
            QMessageBox mess;
            mess.setText("DB not open");
            mess.exec();
        }
    QSqlQuery query;
    if(query.exec("select * from account where username= '" + username+ "' and password= '"+password+"'")){
        int count =0;
        while(query.next()){
            count++;
        }
        if (count>0){
            connClose();
           this->done(3);
        }
        else{
            QMessageBox mess;
            mess.setText("Wrong Password or Username");
            mess.exec();
            connClose();
            return;}

    }

}

void AppointmentCheck::on_pushButton_2_clicked()
{

    CreateNewAccount newacc;
    newacc.setModal(true);
    newacc.exec();
}

bool AppointmentCheck::connOpen(){
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(Path_to_DB);
    QFileInfo checkFile(Path_to_DB);

    if(checkFile.isFile()){
        if(mydb.open()){
            return true;
        }
        else
        {
            QMessageBox mess;
               mess.setText("DB not Open");
               mess.exec();
            return false;
        }
    }
    else return false;
}

void AppointmentCheck::connClose(){
    mydb.close();
}

void AppointmentCheck::on_pushButton_3_clicked()
{
    ForgotPassword FP;
    FP.setModal(true);
    FP.exec();

}
