#include "cancelappointment.h"
#include "ui_cancelappointment.h"

cancelAppointment::cancelAppointment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cancelAppointment)
{
    ui->setupUi(this);
    updateApp();
}

cancelAppointment::~cancelAppointment()
{
    delete ui;
}

void cancelAppointment::updateApp(){
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
    w.connClose();
    w.close();
}





void cancelAppointment::on_pushButton_clicked()
{


    QString userAccount = ui->username->text();
    QString contact=ui->contact->text();
    QString date = ui->date->text();
    AppointmentCheck conn;
    conn.connOpen();
    QSqlQuery qry;
    if(username == "Admin"){
        qry.prepare("DELETE FROM appointment WHERE username = '"+userAccount+"' AND contact = '"+contact+"'AND DateTime ='"+date+"'");

    }
    else
    qry.prepare("DELETE FROM appointment WHERE username = '"+username+"' AND contact = '"+contact+"' AND DateTime = '"+date+"'");

    if(qry.exec()){
        QMessageBox mess;
        mess.setText("Appointment Canceled");
        mess.exec();
    }
    else{
        QMessageBox mess;
        mess.setText("Failed to Update");
        mess.exec();
    }


    conn.connClose();
    updateApp();
}

void cancelAppointment::on_pushButton_2_clicked()
{
    this->close();
}

void cancelAppointment::on_AppointmentView_clicked(const QModelIndex &index)
{
    int row = index.row();
    QString contact;
    QString date;
    QString userAccount;
    if(username =="Admin"){
        userAccount = index.sibling(row, 0).data().toString();
        contact = index.sibling(row, 1).data().toString();
        date= index.sibling(row, 2).data().toString();
        ui->username->setText(userAccount);
    }
    else{
        contact = index.sibling(row, 0).data().toString();
        date = index.sibling(row, 1).data().toString();
    }
    ui->contact->setText(contact);
    ui->date->setText(date);
}
