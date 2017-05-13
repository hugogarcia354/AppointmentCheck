#include "createcontact.h"
#include "ui_createcontact.h"

CreateContact::CreateContact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateContact)
{
    ui->setupUi(this);
}

CreateContact::~CreateContact()
{
    delete ui;
}

void CreateContact::on_buttonBox_accepted()
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


    QString firstName = ui->firstName->text();
    QString lastName = ui->lastName->text();
    QString email = ui->email->text();

    QSqlQuery qry;
    qry.prepare("INSERT INTO contact (firstName, lastName, phone, email)VALUES ('"+firstName+"','"+lastName+"','"+phoneEmail+"','"+email+"')");
    if(qry.exec()){
        QMessageBox mess;
        mess.setText("Contact Created");
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
