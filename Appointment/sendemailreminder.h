#ifndef SENDEMAILREMINDER_H
#define SENDEMAILREMINDER_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QFileInfo>

#include "appointmentcheck.h"
#include "smtp.h"
namespace Ui {
class sendEmailReminder;
}

class sendEmailReminder : public QDialog
{
    Q_OBJECT

public:
    explicit sendEmailReminder(QWidget *parent = 0);
    ~sendEmailReminder();
    void updateApp();
    QString username;
    QString user;
    QString email;
    QString phone;
    QString contactFirst;
    QString contactLast;
    QString contact;
    QString dateTime;
    QString userFirst;
    QString userLast;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_AppointmentView_clicked(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_NowBox_toggled(bool checked);

    void on_MinutesBox_toggled(bool checked);

    void on_DayBox_toggled(bool checked);

    void now();

private:
    Ui::sendEmailReminder *ui;
};

#endif // SENDEMAILREMINDER_H
