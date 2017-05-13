#include "admindelete.h"
#include "ui_admindelete.h"

AdminDelete::AdminDelete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminDelete)
{
    ui->setupUi(this);
    AppointmentCheck list;
    list.connOpen();
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery(list.mydb);

    qry->prepare("select username from account where username not like 'Admin'");

    qry->exec();
    modal->setQuery(*qry);

    ui->AccountBox->setModel(modal);
    list.connClose();
    list.close();
}

AdminDelete::~AdminDelete()
{
    delete ui;
}

void AdminDelete::on_buttonBox_accepted()
{
    QString username = ui->AccountBox->currentText();
    QString password = ui->password->text();
    QMessageBox mess;
    AppointmentCheck conn;
    conn.connOpen();
    QSqlQuery qry;
    bool success = false;
    if(qry.exec("select * from account where username='Admin' and password= '"+password+"'")){
        int count =0;
        while(qry.next()){
            count++;
        }
        if (count>0){
        qry.prepare("delete from appointment where username = '"+username+"'");
        if(qry.exec())
            success = true;
        qry.prepare("delete from account where username='"+username+"'");
        if (qry.exec())
            success = true;
        else
            success = false;
        conn.connClose();
        conn.close();
        }
        else {
            mess.setText("Invalid Password");
            mess.exec();
            return;
        }
    if (success){
    mess.setText("Account Deleted Successfully");
    }
    else
        mess.setText("Failed to delete Account completely");
    mess.exec();}

            }



