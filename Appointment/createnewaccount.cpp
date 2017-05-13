#include "createnewaccount.h"
#include "ui_createnewaccount.h"

CreateNewAccount::CreateNewAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateNewAccount)
{
    ui->setupUi(this);
}

CreateNewAccount::~CreateNewAccount()
{
    delete ui;
}

void CreateNewAccount::on_pushButton_clicked()
{
    AppointmentCheck conn;
    conn.connOpen();
    QString phoneEmail;

    if (!ui->comboBox->currentIndex()==0){
        switch (ui->comboBox->currentIndex()){
        case 1:
            phoneEmail = (ui->phone->text() + "@vzwpix.com");
            break;
        case 2:
            phoneEmail = (ui->phone->text() + "@tmomail.net");
            break;
        case 3:
            phoneEmail = (ui->phone->text() + "@mymetropcs.com");
            break;
        case 4:
            phoneEmail = (ui->phone->text() + "@messaging.sprintpcs.com");
            break;

        }
    };

    QString username = ui->username->text();
    QString password = ui->password->text();
    QString firstName = ui->firstName->text();
    QString lastName = ui->lastName->text();
    QString email = ui->email->text();

    QSqlQuery qry;
    qry.prepare("INSERT INTO account (username, password, firstName, lastName, phone, email)VALUES ('"+username+"','"+password+"','"+firstName+"','"+lastName+"','"+phoneEmail+"','"+email+"')");
    if(qry.exec()){
        QMessageBox mess;
        mess.setText("Account Created");
        mess.exec();
    }
    else{
        QMessageBox mess;
        mess.setText("Failed to Create");
        mess.exec();
    }
    conn.connClose();
    this->close();



}

void CreateNewAccount::on_pushButton_2_clicked()
{
    this->close();
}
