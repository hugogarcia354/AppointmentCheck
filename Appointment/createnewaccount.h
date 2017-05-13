#ifndef CREATENEWACCOUNT_H
#define CREATENEWACCOUNT_H


#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QFileInfo>
#include <QDialog>
#include <QMessageBox>
#include "appointmentcheck.h"
namespace Ui {
class CreateNewAccount;
}

class CreateNewAccount : public QDialog
{
    Q_OBJECT

public:

    explicit CreateNewAccount(QWidget *parent = 0);
    ~CreateNewAccount();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::CreateNewAccount *ui;
};

#endif // CREATENEWACCOUNT_H
