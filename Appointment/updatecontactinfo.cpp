#include "updatecontactinfo.h"
#include "ui_updatecontactinfo.h"

updateContactInfo::updateContactInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::updateContactInfo)
{
    ui->setupUi(this);
}

updateContactInfo::~updateContactInfo()
{
    delete ui;
}

void updateContactInfo::updateUp(){
    ui->firstName->setText(first);
    ui->lastName->setText(last);
    ui->email->setText(email);

    QStringList phonePieces = phone.split("@");
    ui->phone->setText(phonePieces.value(0));


    if(phonePieces.value(1) == "vzwpix.com")
        ui->comboBox->setCurrentIndex(1);
      else if(phonePieces.value(1) =="tmomail.net" )
        ui->comboBox->setCurrentIndex(2);
        else if(phonePieces.value(1) =="mymetropcs.com")
        ui->comboBox->setCurrentIndex(3);
       else
        ui->comboBox->setCurrentIndex(4);

}

void updateContactInfo::on_cancelButton_clicked()
{
    this->close();
}

void updateContactInfo::on_updateButton_clicked()
{

    AppointmentCheck list;
    list.connOpen();
    QSqlQuery * qry = new QSqlQuery(list.mydb);
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
    }

    qry->prepare("UPDATE contact SET firstName = '"+ui->firstName->text()+"', lastName = '"+ui->lastName->text()+"', phone = '"+phoneEmail+"', email = '"+ui->email->text()+"' WHERE firstName = '"+first+"' AND lastName = '"+last+"' AND phone = '"+phone+"' AND email = '"+email+"'");

       QMessageBox mess;
    if(qry->exec()){
        mess.setText("Contacted Updated");
        mess.exec();
    }
    else{
        mess.setText("Failed to Update");
        mess.exec();
    }
    this->close();
}
