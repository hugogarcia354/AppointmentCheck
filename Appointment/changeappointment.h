#ifndef CHANGEAPPOINTMENT_H
#define CHANGEAPPOINTMENT_H

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
class ChangeAppointment;
}

class ChangeAppointment : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeAppointment(QWidget *parent = 0);
    ~ChangeAppointment();
    void updateApp();
    QString userplus;
    QString username;
    bool dayof = false;
    Qt::DayOfWeek day;
    QString color;
    bool grid = false;
    void setUser(QString);

private slots:
    void on_close_clicked();

    void on_AppointmentView_clicked(const QModelIndex &index);

    void on_update_clicked();

    void on_contactList_activated(const QString &arg1);

    void on_timeEdit_timeChanged(const QTime &time);

    void on_dateEdit_dateChanged(const QDate &date);

    void on_userBox_activated(const QString &arg1);

private:
    Ui::ChangeAppointment *ui;
};

#endif // CHANGEAPPOINTMENT_H
