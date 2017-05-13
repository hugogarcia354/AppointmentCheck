#ifndef ADMINCHANGEPASSWORD_H
#define ADMINCHANGEPASSWORD_H

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
class AdminChangePassword;
}

class AdminChangePassword : public QDialog
{
    Q_OBJECT

public:
    explicit AdminChangePassword(QWidget *parent = 0);
    ~AdminChangePassword();
    void updateWin();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AdminChangePassword *ui;
};

#endif // ADMINCHANGEPASSWORD_H
