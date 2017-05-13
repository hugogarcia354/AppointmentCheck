#ifndef HELP_H
#define HELP_H

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
class help;
}

class help : public QDialog
{
    Q_OBJECT

public:
    explicit help(QWidget *parent = 0);
    ~help();
    QString username;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::help *ui;
};

#endif // HELP_H
