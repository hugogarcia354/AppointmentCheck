#include "adminchangepassword.h"
#include "ui_adminchangepassword.h"

AdminChangePassword::AdminChangePassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminChangePassword)
{
    ui->setupUi(this);
}

AdminChangePassword::~AdminChangePassword()
{
    delete ui;
}

void AdminChangePassword::on_buttonBox_accepted()
{
    QMessageBox mess;
    AppointmentCheck w;
    w.connOpen();
    QSqlQuery * qry = new QSqlQuery(w.mydb);
    QString username = ui->usernameBox->currentText();
    QString newpassword = ui->newpassword->text();
    QString confirmPass = ui->confirm->text();
    if(newpassword == confirmPass){
        qry->prepare("UPDATE account SET password = '"+newpassword+"' WHERE username = '"+username+"'");
        if(qry->exec()){
            mess.setText("Password updated successfully");
            mess.exec();
        }
        else{
            mess.setText("Password failed to update");
            mess.exec();
        }
    }
    else{
       mess.setText("New Passwords do not match.");
       mess.exec();
    }
}



void AdminChangePassword::updateWin(){
    AppointmentCheck w;
    w.connOpen();
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery(w.mydb);
    qry->prepare("select username from account");
    qry->exec();
    model->setQuery(*qry);
    ui->usernameBox->setModel(model);
    w.connClose();
}
