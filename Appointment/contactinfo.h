#ifndef CONTACTINFO_H
#define CONTACTINFO_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QFileInfo>
#include "appointmentcheck.h"
#include "updatecontactinfo.h"
namespace Ui {
class contactInfo;
}

class contactInfo : public QDialog
{
    Q_OBJECT

public:
    explicit contactInfo(QWidget *parent = 0);
    ~contactInfo();
    void updateCon();
    QString first,last,phone,email;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_contactView_clicked(const QModelIndex &index);


    void on_AddNewContact_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::contactInfo *ui;
};

#endif // CONTACTINFO_H
