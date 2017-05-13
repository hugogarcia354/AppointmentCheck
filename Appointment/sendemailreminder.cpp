#include "sendemailreminder.h"
#include "ui_sendemailreminder.h"

sendEmailReminder::sendEmailReminder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sendEmailReminder)
{

    ui->setupUi(this);

}

sendEmailReminder::~sendEmailReminder()
{
    delete ui;


}

void sendEmailReminder::on_pushButton_clicked()
{
    AppointmentCheck conn;
    conn.connOpen();
     QMessageBox mess;
    QString body = ("Hello "+contactFirst+" "+contactLast+",\nThis message is to confirm that you have an appointment with "+userFirst+" "+userLast+" on "+dateTime);

     if(!ui->checkBox->isChecked()){
         body = ui->BodyMessage->toPlainText();
     }
    Smtp* smtp = new Smtp("appointmentcheck343@gmail.com","cecs343!","smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    QDateTime appTime = QDateTime::fromString(dateTime,"MM-dd-yyyy hh:mm ap");


    QDateTime current;
    current = current.currentDateTime();





    if(ui->NowBox->isChecked()){
    smtp->sendMail("appointmentcheck343@gmail.com",email,"Reminder/Confirmation",body);

    mess.setText("An Email has been sent to "+contactFirst +" "+contactLast+".");
    mess.exec();
    }

    if(ui->MinutesBox->isChecked()){

        appTime=appTime.addSecs(-60*30);
        int secsTo = current.msecsTo(appTime);


        if(secsTo<0)
            secsTo = 0;
            QTimer::singleShot(secsTo,this,SLOT(now()));
            QTimer::singleShot(secsTo+1,this,SLOT(on_pushButton_clicked()));
    }
    if(ui->DayBox->isChecked()){


        appTime=appTime.addSecs(-60*60*24);
        int secsTo = current.msecsTo(appTime);

        if(secsTo<0)
            secsTo = 0;
        QTimer::singleShot(secsTo,this,SLOT(now()));
        QTimer::singleShot(secsTo+1,this,SLOT(on_pushButton_clicked()));


    }
}




void sendEmailReminder::updateApp(){
    AppointmentCheck w;
    w.connOpen();
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery(w.mydb);

    if(username == "Admin"){
         qry->prepare("select username,contact,DateTime from appointment");
    }
    else
    qry->prepare("select contact,DateTime from appointment where username='"+username+"'");


    qry->exec();
    model->setQuery(*qry);
    ui->AppointmentView->setModel(model);

    QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
    m->setDynamicSortFilter(true);
    m->setSourceModel(model);
    ui->AppointmentView->setModel(m);
    ui->AppointmentView->setSortingEnabled(true);

    qry->prepare("select firstName,lastName from account where username='"+username+"'");
    qry->exec();
    while(qry->next()){
    userFirst=qry->value(0).toString();
    userLast=qry->value(1).toString();
    }
    w.connClose();
    w.close();
}




void sendEmailReminder::on_pushButton_2_clicked()
{
    this->hide();
}




void sendEmailReminder::on_AppointmentView_clicked(const QModelIndex &index)
{
    int row = index.row();

    if(username =="Admin"){
        user = index.sibling(row, 0).data().toString();
        contact = index.sibling(row, 1).data().toString();
        dateTime = index.sibling(row, 2).data().toString();

    }
    else{
        user = username;
        contact = index.sibling(row, 0).data().toString();
        dateTime = index.sibling(row, 1).data().toString();
    }
    ui->contactLabel->setText(contact);
    ui->appointmentLabel->setText(dateTime);

    AppointmentCheck w;
    w.connOpen();
    QSqlQuery * qry = new QSqlQuery(w.mydb);

    qry->prepare("select firstName,lastName,phone,email from contact where firstName = '"+contact+"'");
    qry->exec();
    while(qry->next()){
    contactFirst = qry->value(0).toString();
    contactLast = qry->value(1).toString();
    phone = qry->value(2).toString();
    email = qry->value(3).toString();
}

}

void sendEmailReminder::on_pushButton_3_clicked()
{
    AppointmentCheck conn;
    conn.connOpen();

    QString body = ("Hello "+contactFirst+" "+contactLast+",\nThis message is to confirm that you have an appointment with "+userFirst+" "+userLast+" on "+dateTime);

     if(!ui->checkBox->isChecked()){
         body = ui->BodyMessage->toPlainText();
     }
    Smtp* smtp = new Smtp("appointmentcheck343@gmail.com","cecs343!","smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));



    QDateTime appTime = QDateTime::fromString(dateTime,"MM-dd-yyyy hh:mm ap");


    QDateTime current;
    current = current.currentDateTime();


    if(ui->NowBox->isChecked()){
    smtp->sendMail("appointmentcheck343@gmail.com",phone,"Reminder/Confirmation",body);
    QMessageBox mess;
    mess.setText("A Text Message has been sent to "+contactFirst +" "+contactLast+".");
    mess.exec();
    }


    if(ui->MinutesBox->isChecked()){

        appTime=appTime.addSecs(-60*30);
        int secsTo = current.msecsTo(appTime);

    if(secsTo<0)
        secsTo = 0;

            QTimer::singleShot(secsTo,this,SLOT(now()));
            QTimer::singleShot(secsTo+1,this,SLOT(on_pushButton_3_clicked()));
    }
    if(ui->DayBox->isChecked()){

        appTime=appTime.addSecs(-60*60*24);
        int secsTo = current.msecsTo(appTime);

        if(secsTo<0)
            secsTo = 0;


        QTimer::singleShot(secsTo,this,SLOT(now()));
        QTimer::singleShot(secsTo+1,this,SLOT(on_pushButton_3_clicked()));


    }
}


void sendEmailReminder::on_NowBox_toggled(bool checked)
{
    if(checked){
        ui->DayBox->setChecked(false);
        ui->MinutesBox->setChecked(false);
        ui->pushButton->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
    }
}

void sendEmailReminder::on_MinutesBox_toggled(bool checked)
{
    if(checked){
        ui->DayBox->setChecked(false);
        ui->NowBox->setChecked(false);
        ui->pushButton->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
    }
}

void sendEmailReminder::on_DayBox_toggled(bool checked)
{
    if(checked){
        ui->MinutesBox->setChecked(false);
        ui->NowBox->setChecked(false);
        ui->pushButton->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
    }
}


void sendEmailReminder::now(){
    ui->NowBox->setChecked(true);
}
