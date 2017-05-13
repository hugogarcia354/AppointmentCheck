#ifndef CANCELAPPOINTMENT_H
#define CANCELAPPOINTMENT_H

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
class cancelAppointment;
}

class cancelAppointment : public QDialog
{
    Q_OBJECT

public:
    explicit cancelAppointment(QWidget *parent = 0);
    ~cancelAppointment();
    QString username;

    void updateApp();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_AppointmentView_clicked(const QModelIndex &index);

private:
    Ui::cancelAppointment *ui;
};

#endif // CANCELAPPOINTMENT_H
