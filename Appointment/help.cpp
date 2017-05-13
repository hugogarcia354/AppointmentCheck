#include "help.h"
#include "ui_help.h"

help::help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help)
{
    ui->setupUi(this);
}

help::~help()
{
    delete ui;
}

void help::on_buttonBox_accepted()
{
    AppointmentCheck conn;
    conn.connOpen();
    QString body = ui->bodyBox->toPlainText();
    body+="\n \n From: "+ username;
    Smtp* smtp = new Smtp("appointmentcheck343@gmail.com","cecs343!","smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    smtp->sendMail("appointmentcheck343@gmail.com","appointmentcheck343@gmail.com","Help Requested",body);
}
