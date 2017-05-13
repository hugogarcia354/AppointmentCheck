#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //checking login info
    AppointmentCheck w;

    int login = w.exec();
   //If login succesfull, open mainwindow.
   if(login == 3){
    ui->setupUi(this);
    this->username=w.username; //mainwindow username gets username from login.
    updateMain(); //updates calendar, appointment list
   }
   else{
       this->~MainWindow();//deletes window
   }



}

MainWindow::~MainWindow()
{
    delete ui;
}

///
/// \brief MainWindow::on_actionBlue_triggered
///changes calendar color to blue
/// also stores calendar color to this.color.
void MainWindow::on_actionBlue_triggered()
{
      color ="background-color: rgb(0, 85, 255);alternate-background-color: rgb(0, 170, 255);selection-background-color: rgb(0, 170, 255);";
      ui->calendarWidget->setStyleSheet("background-color: rgb(0, 85, 255);alternate-background-color: rgb(0, 170, 255);selection-background-color: rgb(0, 170, 255);");
}

///
/// \brief MainWindow::on_actionRed_triggered
///changes calendar color to red
/// also stores calendar color to this.color.
void MainWindow::on_actionRed_triggered()
{
    color = "background-color: rgb(255, 0, 0);";
    ui->calendarWidget->setStyleSheet("background-color: rgb(200, 50, 0);");
}

///
/// \brief MainWindow::on_actionPurple_triggered
///changes calendar color to purple
/// also stores calendar color to this.color.
void MainWindow::on_actionPurple_triggered()
{
    color = "background-color: rgb(170, 0, 127);";
    ui->calendarWidget->setStyleSheet("background-color: rgb(170, 0, 127);");
}

///
/// \brief MainWindow::on_actionDefault_triggered
///changes calendar color back to default
/// also stores calendar color to this.color.
void MainWindow::on_actionDefault_triggered()
{
    color = "background-color: ";
    ui->calendarWidget->setStyleSheet("background-color: ");
}

///
/// \brief MainWindow::on_actionGridlines_triggered
/// \param checked
///sets calendar grid visibility.
void MainWindow::on_actionGridlines_triggered(bool checked)
{
     ui->calendarWidget->setGridVisible(checked);
     grid = checked;
}

///
/// \brief MainWindow::on_actionSunday_triggered
///sets first day of week.
/// sets what day it is to this.day
void MainWindow::on_actionSunday_triggered()
{

        ui->calendarWidget->setFirstDayOfWeek(Qt::Sunday);
        dayof=true; //to be used only if calendar day gets changed
        day = Qt::Sunday;
}

///
/// \brief MainWindow::on_actionMonday_triggered
///sets first day of week.
void MainWindow::on_actionMonday_triggered()
{

        ui->calendarWidget->setFirstDayOfWeek(Qt::Monday);
        dayof=true;
        day = Qt::Monday;
}

///
/// \brief MainWindow::on_actionTuesday_triggered
///sets first day of week.
void MainWindow::on_actionTuesday_triggered()
{

    ui->calendarWidget->setFirstDayOfWeek(Qt::Tuesday);
    dayof=true;
    day = Qt::Tuesday;
}

///
/// \brief MainWindow::on_actionWednesday_triggered
///sets first day of week.
void MainWindow::on_actionWednesday_triggered()
{

    ui->calendarWidget->setFirstDayOfWeek(Qt::Wednesday);
    dayof=true;
    day = Qt::Wednesday;
}

///
/// \brief MainWindow::on_actionThursday_triggered
///sets first day of week.
void MainWindow::on_actionThursday_triggered()
{

    ui->calendarWidget->setFirstDayOfWeek(Qt::Thursday);
    dayof=true;
    day = Qt::Thursday;
}

///
/// \brief MainWindow::on_actionFriday_triggered
///sets first day of week.
void MainWindow::on_actionFriday_triggered()
{

    ui->calendarWidget->setFirstDayOfWeek(Qt::Friday);
    dayof=true;
    day = Qt::Friday;
}

///
/// \brief MainWindow::on_actionSaturday_triggered
///sets first day of week.
void MainWindow::on_actionSaturday_triggered()
{

    ui->calendarWidget->setFirstDayOfWeek(Qt::Saturday);
    dayof=true;
    day = Qt::Saturday;
}

///
/// \brief MainWindow::on_actionCreate_Account_triggered
///open up CreateNewAccount dialog
void MainWindow::on_actionCreate_Account_triggered()
{
    CreateNewAccount newacc;
    newacc.setModal(true);
    newacc.exec();
}

///
/// \brief MainWindow::on_actionLog_Out_triggered
///log out of account
void MainWindow::on_actionLog_Out_triggered()
{
       this->hide();//hides current mainwindow
       MainWindow* secLog = new MainWindow; //create new instance of MainWindow and show
       secLog->activateWindow();
       secLog->show();
}

///
/// \brief MainWindow::on_actionAdd_New_Contact_triggered
///open up CreateContact window
void MainWindow::on_actionAdd_New_Contact_triggered()
{
    CreateContact C;
    C.setModal(true);
    C.exec();
}

///
/// \brief MainWindow::on_actionCreate_Appointment_triggered
///opens up CreateAppointment dialog
/// dialog is given username and calendar settings.

void MainWindow::on_actionCreate_Appointment_triggered()
{
    createAppointment A;
    A.setModal(true);
    A.username = this->username;

    A.dayof = dayof;
    A.day = this->day;
    A.color = this->color;
    A.grid = this->grid;
    A.updateApp(); //update window before showing
    A.exec();
    updateMain(); //update main window after creating appointment
}

///
/// \brief MainWindow::updateMain
///logic to update all aspects of mainwindow
void MainWindow::updateMain(){
    //open up database
    AppointmentCheck w;
    w.connOpen();

    QSqlQueryModel * model = new QSqlQueryModel();//create model for tableview
    QSqlQuery * qry = new QSqlQuery(w.mydb); //create query for database


    // different functions depending on authority of user.
    if(username == "Admin"){
         qry->prepare("select username,contact,DateTime from appointment");
    }
    else
    qry->prepare("select contact,DateTime from appointment where username='"+username+"'");

    qry->exec();
    model->setQuery(*qry);
    ui->AppointmentView->setModel(model); //set appointment view from query model

    //allow table to be sortable
    QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
    m->setDynamicSortFilter(true);
    m->setSourceModel(model);
    ui->AppointmentView->setModel(m);
    ui->AppointmentView->setSortingEnabled(true);

    //text format to highlight appointment dates on calendar.
    QTextCharFormat text;
    text.setFontWeight(22);
    text.setFontUnderline(true);


    if(username == "Admin"){
        qry->prepare("select username,contact,DateTime from appointment");
    }
    else{
    qry->prepare("select contact,DateTime from appointment where username='"+username+"'");
    }
    //get the count of how many appointments exist.
    int count = 0;
    qry->exec();
    while(qry->next()){
        count++;
    }

    QDate appointment; //to get appointment date from database

    //highlight appointments on calendar
    if(username == "Admin"){
        for(int i = 0; i<count; i++){
         QString dateTime = ui->AppointmentView->model()->data(ui->AppointmentView->model()->index(i,2)).toString();

         QStringList datePieces = dateTime.split(" "); //split up to get date only

         appointment = QDate::fromString(datePieces.value(0),"MM-dd-yyyy");

         if(appointment  < QDate::currentDate()){ //if appointment is past, highlight red
             text.setBackground(QColor(255, 0, 0, 127));
         }
         else if (appointment  == QDate::currentDate()){ //if appointment is current day, highlight green
             text.setBackground(Qt::green);
         }
         else{
             text.setBackground(Qt::yellow); //highlight yellow for future dates
         }

        ui->calendarWidget->setDateTextFormat(appointment,text); //sets highlights day by day
    }
    }
        else{
        //Calendar highlights for regular users
    for(int i = 0; i<count; i++){
     QString dateTime = ui->AppointmentView->model()->data(ui->AppointmentView->model()->index(i,1)).toString();

     QStringList datePieces = dateTime.split(" ");//split up to get date only

     appointment = QDate::fromString(datePieces.value(0),"MM-dd-yyyy");

     if(appointment  < QDate::currentDate()){ //if appointment is past, highlight red
         text.setBackground(QColor(255, 0, 0, 127));
     }
     else if (appointment  == QDate::currentDate()){//if appointment is current day, highlight green
         text.setBackground(Qt::green);
     }
     else{
         text.setBackground(Qt::yellow);//sets highlights day by day
     }
    ui->calendarWidget->setDateTextFormat(appointment,text);//sets highlights day by day

    //table view highlights.
    if(appointment < QDate::currentDate()){
       ui->AppointmentView->model()->setData(ui->AppointmentView->model()->index(i,1),QBrush(QColor(Qt::red)),Qt::ForegroundRole);
    }
    }
}

    //check if user needs to change password
    if(qry->exec("select * from account where username = '"+username+"' and forgotPass is not null")){
        int count =0;
        while(qry->next()){
            count++; //checks if user had a forgotPass variable in DB
        }
        if (count>0){ //if so, then open up Change Password
            ChangePassword ch;
            ch.username = username;
            ch.setModal(false);
            ch.exec();
            updateMain();
        }
    }
    QSqlQueryModel * model2 = new QSqlQueryModel();//create model for tableview
    QSqlQuery *qry2 = new QSqlQuery(w.mydb);
    qry2->prepare("select Monday,Tuesday,Wednesday,Thursday,Friday, Saturday,Sunday from account where username='"+username+"'");

    qry2->exec();
    model2->setQuery(*qry2);
    QTableView *table = new QTableView();
    table->setModel(model2); //set appointment view from query model


    if(qry->exec("select * from account where username = '"+username+"' and Monday is not null")){
        int count =0;
        while(qry->next()){
            count++; //checks if user has schedule for monday
        }
        if (count>0){

    QString Time = table->model()->data(table->model()->index(0,0)).toString();
    ui->MondayLabel->setText("Monday: "+Time);
        }

    else
         ui->MondayLabel->setText("Monday: Not Available");
    }

    if(qry->exec("select * from account where username = '"+username+"' and Tuesday is not null")){
        int count =0;
        while(qry->next()){
            count++; //checks if user has schedule for monday
        }
        if (count>0){

    QString Time = table->model()->data(table->model()->index(0,1)).toString();
    ui->TuesdayLabel->setText("Tuesday: "+Time);
        }

    else
         ui->TuesdayLabel->setText("Tuesday: Not Available");
    }
    if(qry->exec("select * from account where username = '"+username+"' and Wednesday is not null")){
        int count =0;
        while(qry->next()){
            count++; //checks if user has schedule for monday
        }
        if (count>0){

    QString Time = table->model()->data(table->model()->index(0,2)).toString();
    ui->WednesdayLabel->setText("Wednesday: "+Time);
        }

    else
         ui->WednesdayLabel->setText("Wednesday: Not Available");
    }
    if(qry->exec("select * from account where username = '"+username+"' and Thursday is not null")){
        int count =0;
        while(qry->next()){
            count++; //checks if user has schedule for monday
        }
        if (count>0){

    QString Time = table->model()->data(table->model()->index(0,3)).toString();
    ui->ThursdayLabel->setText("Thursday: "+Time);
        }

    else
         ui->ThursdayLabel->setText("Thursday: Not Available");
    }
    if(qry->exec("select * from account where username = '"+username+"' and Friday is not null")){
        int count =0;
        while(qry->next()){
            count++; //checks if user has schedule for monday
        }
        if (count>0){

    QString Time = table->model()->data(table->model()->index(0,4)).toString();
    ui->FridayLabel->setText("Friday: "+Time);
        }

    else
         ui->FridayLabel->setText("Friday: Not Available");
    }
    if(qry->exec("select * from account where username = '"+username+"' and Saturday is not null")){
        int count =0;
        while(qry->next()){
            count++; //checks if user has schedule for monday
        }
        if (count>0){

    QString Time = table->model()->data(table->model()->index(0,5)).toString();
    ui->SaturdayLabel->setText("Saturday: "+Time);
        }

    else
         ui->SaturdayLabel->setText("Saturday: Not Available");
    }
    if(qry->exec("select * from account where username = '"+username+"' and Sunday is not null")){
        int count =0;
        while(qry->next()){
            count++; //checks if user has schedule for monday
        }
        if (count>0){

    QString Time = table->model()->data(table->model()->index(0,6)).toString();
    ui->SundayLabel->setText("Sunday: "+Time);
        }

    else
         ui->SundayLabel->setText("Sunday: Not Available");
    }




    w.connClose();
    w.close();//close DB

}

///
/// \brief MainWindow::on_actionDelete_Account_triggered
///opens up DeleteAccount if regular user or Admin Delete if Admin.
void MainWindow::on_actionDelete_Account_triggered()
{
    if(username == "Admin"){
        AdminDelete ad;
        ad.setModal(true);
        ad.exec();
        updateMain();
    }
    else{
        deleteaccount del;
        del.username = username; //del gets username from this.
        del.setModal(true);
        int log =del.exec();
        //if username deletes account. Reopen mainWindow, first log in.
        if(log !=0){
            this->window()->close();
             if(log==3){
               MainWindow* main = new MainWindow;
                main->show();
              }
        }
    }


}

///
/// \brief MainWindow::on_actionChange_Appointment_triggered
///open up change appointment dialog. First update MainWindow calendar to dehighlight current appointments.
/// Then set calendar settings and username. If admin, open admin window else regular window.
void MainWindow::on_actionChange_Appointment_triggered()
{
    /////////////////////////////////
    /// to dehighlight calendar
    ///
    AppointmentCheck w;
    w.connOpen();
   // QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery(w.mydb);

    QTextCharFormat text;
    text.setFontWeight(22);
    text.setFontUnderline(true);

    if(username == "Admin"){
        qry->prepare("select username,contact,DateTime from appointment");
    }
    else{
    qry->prepare("select contact,DateTime from appointment where username='"+username+"'");
    }
    int count = 0;
    qry->exec();
    while(qry->next()){
        count++;
    }

    QDate appointment;

    if(username == "Admin"){
        for(int i = 0; i<count; i++){
         QString dateTime = ui->AppointmentView->model()->data(ui->AppointmentView->model()->index(i,2)).toString();

         QStringList datePieces = dateTime.split(" ");

         appointment = QDate::fromString(datePieces.value(0),"MM-dd-yyyy");

             text.setBackground(Qt::white);

        ui->calendarWidget->setDateTextFormat(appointment,text);
    }
    }
        else{
        //Calendar highlights
    for(int i = 0; i<count; i++){
     QString dateTime = ui->AppointmentView->model()->data(ui->AppointmentView->model()->index(i,1)).toString();

     QStringList datePieces = dateTime.split(" ");

     appointment = QDate::fromString(datePieces.value(0),"MM-dd-yyyy");

         text.setBackground(Qt::white);



    ui->calendarWidget->setDateTextFormat(appointment,text);
        }
    }

    ///////////
    /// end of dehighlight
    ///

    ChangeAppointment ch;
    ch.setUser(username);
    ch.setModal(true);
//set calendar settings.
    ch.dayof = dayof;
    ch.day = this->day;
    ch.color = this->color;
    ch.grid = this->grid;
    ch.updateApp();
    ch.exec();
    updateMain();
}



void MainWindow::on_actionCancel_Appointment_triggered()
{
    AppointmentCheck w;
    w.connOpen();
   // QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery(w.mydb);

    QTextCharFormat text;
    text.setFontWeight(22);
    text.setFontUnderline(true);

    if(username == "Admin"){
        qry->prepare("select username,contact,DateTime from appointment");
    }
    else{
    qry->prepare("select contact,DateTime from appointment where username='"+username+"'");
    }
    int count = 0;
    qry->exec();
    while(qry->next()){
        count++;
    }

    QDate appointment;

    if(username == "Admin"){
        for(int i = 0; i<count; i++){
         QString dateTime = ui->AppointmentView->model()->data(ui->AppointmentView->model()->index(i,2)).toString();

         QStringList datePieces = dateTime.split(" ");

         appointment = QDate::fromString(datePieces.value(0),"MM-dd-yyyy");

             text.setBackground(Qt::white);

        ui->calendarWidget->setDateTextFormat(appointment,text);
    }
    }
        else{
        //Calendar highlights
    for(int i = 0; i<count; i++){
     QString dateTime = ui->AppointmentView->model()->data(ui->AppointmentView->model()->index(i,1)).toString();

     QStringList datePieces = dateTime.split(" ");

     appointment = QDate::fromString(datePieces.value(0),"MM-dd-yyyy");

         text.setBackground(Qt::white);



    ui->calendarWidget->setDateTextFormat(appointment,text);
        }
    }



    cancelAppointment ca;
    ca.username = username;
    ca.setModal(true);
    ca.updateApp();
    ca.exec();
    updateMain();
}

void MainWindow::on_actionView_Contact_List_triggered()
{
    contactInfo info;
    info.setModal(true);
    info.updateCon();
    info.exec();
}

void MainWindow::on_actionSend_Reminders_triggered()
{
    sendEmailReminder *email = new sendEmailReminder();
    email->username = username;
    email->updateApp();
    email->setModal(true);
    email->show();
}

void MainWindow::on_actionChange_Password_triggered()
{
    if(username == "Admin"){
     AdminChangePassword adch;
     adch.updateWin();
     adch.setModal(true);
     adch.exec();

    }
    else{
    ChangePassword ch;
    ch.username = username;
    ch.setModal(true);
    ch.exec();
    }
}

void MainWindow::on_actionContact_Admin_triggered()
{
    help halp;
    halp.username =username;
    halp.setModal(true);
    halp.exec();
}

void MainWindow::on_actionAbout_AppointmentCheck_triggered()
{
    AboutUs us;
    us.setModal(false);
    us.exec();
}

void MainWindow::on_actionList_Appointment_in_Range_triggered()
{
    listedRange ls;
    ls.setModal(true);
    ls.username = username;
    ls.exec();
}

void MainWindow::on_AvailabilityButton_clicked()
{
    Availability av;
    av.username = username;
    av.setModal(true);
    av.update();
    av.exec();
    updateMain();
}
