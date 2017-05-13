#ifndef UPDATECONTACTINFO_H
#define UPDATECONTACTINFO_H

#include <QDialog>

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QFileInfo>
#include "appointmentcheck.h"
namespace Ui {
class updateContactInfo;
}

class updateContactInfo : public QDialog
{
    Q_OBJECT

public:
    explicit updateContactInfo(QWidget *parent = 0);
    ~updateContactInfo();
    QString first,last,email,phone;
    int index;
    void updateUp();

private slots:
    void on_cancelButton_clicked();

    void on_updateButton_clicked();

private:
    Ui::updateContactInfo *ui;
};

#endif // UPDATECONTACTINFO_H
