#ifndef FORGOTPASSWORD_H
#define FORGOTPASSWORD_H

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
#include "time.h"
namespace Ui {
class ForgotPassword;
}

class ForgotPassword : public QDialog
{
    Q_OBJECT

public:
    explicit ForgotPassword(QWidget *parent = 0);
    ~ForgotPassword();
    QString int2String(int);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ForgotPassword *ui;
};

#endif // FORGOTPASSWORD_H
