#ifndef CREATECONTACT_H
#define CREATECONTACT_H

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
class CreateContact;
}

class CreateContact : public QDialog
{
    Q_OBJECT

public:
    explicit CreateContact(QWidget *parent = 0);
    ~CreateContact();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::CreateContact *ui;
};

#endif // CREATECONTACT_H
