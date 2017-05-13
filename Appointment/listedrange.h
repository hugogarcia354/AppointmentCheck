#ifndef LISTEDRANGE_H
#define LISTEDRANGE_H

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
class listedRange;
}

class listedRange : public QDialog
{
    Q_OBJECT

public:
    explicit listedRange(QWidget *parent = 0);
    ~listedRange();
    QString username;
    QDate startTime;
    QDate endTime;

private slots:
    void on_StartDate_dateChanged(const QDate &date);

    void on_EndDate_dateChanged(const QDate &date);

    void on_MonthStart_dateChanged(const QDate &date);

    void on_MonthEnd_dateChanged(const QDate &date);

    void on_WeekBox_toggled(bool checked);

    void on_MonthBox_toggled(bool checked);

    void on_AnyBox_toggled(bool checked);

    void on_pushButton_clicked();

    void on_AnyStart_dateChanged(const QDate &date);

    void on_AnyEnd_dateChanged(const QDate &date);

private:
    Ui::listedRange *ui;
};

#endif // LISTEDRANGE_H
