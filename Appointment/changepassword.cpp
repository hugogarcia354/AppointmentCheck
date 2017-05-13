#include "changepassword.h"
#include "ui_changepassword.h"

ChangePassword::ChangePassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePassword)
{
    ui->setupUi(this);
}

ChangePassword::~ChangePassword()
{
    delete ui;
}

void ChangePassword::on_buttonBox_accepted()
{
    AppointmentCheck list;
    QMessageBox mess;
    list.connOpen();
    QSqlQuery * query = new QSqlQuery(list.mydb);
    QString current = ui->current->text();
    QString newpassword = ui->newpassword->text();
    QString confirmPass = ui->confirm->text();

    if(query->exec("select * from account where username= '" + username+ "' and password= '"+current+"'")){
        int count =0;
        while(query->next()){
            count++;
        }
        if (count>0){
            if(newpassword == confirmPass){
                query->prepare("UPDATE account SET password = '"+newpassword+"' WHERE username = '"+username+"'");
                if(query->exec()){
                    mess.setText("Password updated successfully");
                    mess.exec();
                }
                else{
                    mess.setText("Password failed to update");
                    mess.exec();
                }
                query->prepare("UPDATE account SET forgotPass = NULL WHERE username = '"+username+"'");
                query->exec();
            }
            else{
               mess.setText("New Passwords do not match.");
               mess.exec();
            }
        }
        else{
            mess.setText("Current Password does not match.");
            mess.exec();
        }
}
}
