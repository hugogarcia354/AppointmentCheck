#ifndef AVAILABILITY_H
#define AVAILABILITY_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QFileInfo>
#include <QTableView>

#include "appointmentcheck.h"
namespace Ui {
class Availability;
}

class Availability : public QDialog
{
    Q_OBJECT

public:
    explicit Availability(QWidget *parent = 0);
    ~Availability();
    QString username;
    void update();

private slots:
    void on_MondayBox_toggled(bool checked);

    void on_SundayBox_toggled(bool checked);

    void on_TuesdayBox_toggled(bool checked);

    void on_WednesdayBox_toggled(bool checked);

    void on_ThursdayBox_toggled(bool checked);

    void on_FridayBox_toggled(bool checked);

    void on_SaturdayBox_toggled(bool checked);

    void on_buttonBox_accepted();


    void on_userBox_activated(const QString &arg1);

private:
    Ui::Availability *ui;
};

#endif // AVAILABILITY_H
