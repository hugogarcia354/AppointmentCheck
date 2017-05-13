#ifndef APPOINTMENTCHECK_H
#define APPOINTMENTCHECK_H

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QFileInfo>
#include "mainwindow.h"
#include "createnewaccount.h"
#include <QDialog>

namespace Ui {
class AppointmentCheck;
}

class AppointmentCheck : public QDialog
{
    Q_OBJECT

public:
    QString username;
    QSqlDatabase mydb;
    void connClose();
    bool connOpen();
    bool open;
    explicit AppointmentCheck(QWidget *parent = 0);
    ~AppointmentCheck();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::AppointmentCheck *ui;

};

#endif // APPOINTMENTCHECK_H
