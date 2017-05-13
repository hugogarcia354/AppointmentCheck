#include "deleteaccount.h"
#include "ui_deleteaccount.h"

deleteaccount::deleteaccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteaccount)
{
    ui->setupUi(this);
}

deleteaccount::~deleteaccount()
{
    delete ui;
}

void deleteaccount::on_buttonBox_accepted()
{
    QString password = ui->password->text();
    QMessageBox mess;
    AppointmentCheck conn;
    conn.connOpen();
    QSqlQuery qry;
    bool success = false;
    if(qry.exec("select * from account where username='"+username+"' and password= '"+password+"'")){
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
    this->done(3);
    }
    else
        mess.setText("Failed to delete Account completely");
    mess.exec();}
}
