#include "contactinfo.h"
#include "ui_contactinfo.h"

contactInfo::contactInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::contactInfo)
{
    ui->setupUi(this);
    updateCon();
}

contactInfo::~contactInfo()
{
    delete ui;
}
void contactInfo::updateCon(){
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    AppointmentCheck w;
    w.connOpen();
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery(w.mydb);

    qry->prepare("select * from contact");


    qry->exec();
    model->setQuery(*qry);
    ui->contactView->setModel(model);

    QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
    m->setDynamicSortFilter(true);
    m->setSourceModel(model);
    ui->contactView->setModel(m);
    ui->contactView->setSortingEnabled(true);

    w.connClose();
    w.close();
}

void contactInfo::on_pushButton_clicked()
{
    this->close();
}

void contactInfo::on_pushButton_2_clicked()
{
    updateContactInfo up;
    up.first = first;
    up.last = last;
    up.phone = phone;
    up.email = email;
    up.setModal(true);
    up.updateUp();
    up.exec();
    updateCon();
}



void contactInfo::on_contactView_clicked(const QModelIndex &index)
{
    int row = index.row();


        first = index.sibling(row, 0).data().toString();
        last = index.sibling(row, 1).data().toString();
        phone = index.sibling(row, 2).data().toString();
        email = index.sibling(row, 3).data().toString();
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_4->setEnabled(true);
}


void contactInfo::on_AddNewContact_clicked()
{
    CreateContact C;
    C.setModal(true);
    C.exec();
    updateCon();
}

void contactInfo::on_pushButton_4_clicked()
{
    QMessageBox mess;

    AppointmentCheck conn;
    conn.connOpen();
    QSqlQuery qry;
    bool success = false;
    qry.prepare("DELETE FROM contact WHERE firstName = '"+first+"' AND lastName = '"+last+"'");
    if(qry.exec()){
      success = true;
      conn.connClose();
      conn.close();
        }

    if (success)
        mess.setText("Contact Deleted Successfully");

    else
        mess.setText("Failed to delete Contact completely");
    mess.exec();
   updateCon();
}


