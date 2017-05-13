#ifndef ADMINDELETE_H
#define ADMINDELETE_H

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
class AdminDelete;
}

class AdminDelete : public QDialog
{
    Q_OBJECT

public:
    explicit AdminDelete(QWidget *parent = 0);
    ~AdminDelete();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AdminDelete *ui;
};

#endif // ADMINDELETE_H
