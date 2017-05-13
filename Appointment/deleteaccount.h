#ifndef DELETEACCOUNT_H
#define DELETEACCOUNT_H

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
class deleteaccount;
}

class deleteaccount : public QDialog
{
    Q_OBJECT

public:
    explicit deleteaccount(QWidget *parent = 0);
    ~deleteaccount();
    QString username;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::deleteaccount *ui;
};

#endif // DELETEACCOUNT_H
