#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTextCharFormat>
#include "appointmentcheck.h"
#include "createcontact.h"
#include "createappointment.h"
#include "admindelete.h"
#include "deleteaccount.h"
#include "changeappointment.h"
#include "cancelappointment.h"
#include "contactinfo.h"
#include "sendemailreminder.h"
#include "updatecontactinfo.h"
#include "changepassword.h"
#include "adminchangepassword.h"
#include "forgotpassword.h"
#include "help.h"
#include "aboutus.h"
#include "listedrange.h"
#include "availability.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString username;
    Qt::DayOfWeek day;
    bool dayof = false;
    QString color ="";
    bool grid = false;

private slots:
    void on_actionBlue_triggered();

    void on_actionRed_triggered();

    void on_actionPurple_triggered();

    void on_actionDefault_triggered();

    void on_actionGridlines_triggered(bool checked);

    void on_actionSunday_triggered();

    void on_actionMonday_triggered();

    void on_actionTuesday_triggered();

    void on_actionWednesday_triggered();

    void on_actionThursday_triggered();

    void on_actionFriday_triggered();

    void on_actionSaturday_triggered();

    void on_actionCreate_Account_triggered();

    void on_actionLog_Out_triggered();

    void on_actionAdd_New_Contact_triggered();

    void on_actionCreate_Appointment_triggered();

    void on_actionDelete_Account_triggered();

    void on_actionChange_Appointment_triggered();

    void on_actionCancel_Appointment_triggered();

    void on_actionView_Contact_List_triggered();

    void on_actionSend_Reminders_triggered();

    void on_actionChange_Password_triggered();

    void on_actionContact_Admin_triggered();

    void on_actionAbout_AppointmentCheck_triggered();

    void on_actionList_Appointment_in_Range_triggered();

    void on_AvailabilityButton_clicked();

public slots:
    void updateMain();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
