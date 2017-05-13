#ifndef CREATEAPPOINTMENT_H
#define CREATEAPPOINTMENT_H

#include <QDialog>

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QFileInfo>
#include <QCalendarWidget>

#include "appointmentcheck.h"
namespace Ui {
class createAppointment;
}

class createAppointment : public QDialog
{
    Q_OBJECT

public:
    explicit createAppointment(QWidget *parent = 0);
    ~createAppointment();
    QString username;
    bool dayof = false;
    Qt::DayOfWeek day;
    QString color;
    bool grid = false;
    void updateApp();

private slots:


    void on_buttonBox_accepted();

private:
    Ui::createAppointment *ui;
};

#endif // CREATEAPPOINTMENT_H
