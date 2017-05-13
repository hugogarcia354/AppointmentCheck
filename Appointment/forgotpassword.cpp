#include "forgotpassword.h"
#include "ui_forgotpassword.h"

ForgotPassword::ForgotPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ForgotPassword)
{
    ui->setupUi(this);
}

ForgotPassword::~ForgotPassword()
{
    delete ui;
}

void ForgotPassword::on_buttonBox_accepted()
{
    AppointmentCheck list;
    QMessageBox mess;
    list.connOpen();
    QSqlQuery * query = new QSqlQuery(list.mydb);
    QString username = ui->username->text();
    QString email = ui->email->text();

    if(query->exec("select * from account where username= '" + username+ "' and email= '"+email+"'")){
        int count =0;
        while(query->next()){
            count++;
        }
        if (count>0){

            int tp[5];
            QString temp;
            qsrand(time(NULL));
            for (int i = 0; i < 5; i++)
            {
                tp[i] = qrand() % 36;
            }

            for (int j = 0; j < 5; j++)
            {
                temp += int2String(tp[j]);
            }


            query->prepare("update account set password = '"+temp+"' WHERE username = '"+username+"' and email = '"+email+"'");
            if(query->exec()){
                QString body = (username+" your password has been changed to \""+temp+"\". Please login and change your password");

                Smtp* smtp = new Smtp("appointmentcheck343@gmail.com","cecs343!","smtp.gmail.com");
                connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

                smtp->sendMail("appointmentcheck343@gmail.com",email,"Forgot Password",body);
                mess.setText("An Email has been sent to you for further instructions");
                mess.exec();
                query->prepare("update account set forgotPass = '1' WHERE username = '"+username+"' and email = '"+email+"'");
                query->exec();
            }
            else{
                mess.setText("Error: Please Contact Admin for further assistance");
                mess.exec();
            }

        }
        else{
            mess.setText("Account not found");
            mess.exec();
        }
        }
}

QString ForgotPassword::int2String(int n){

        QString str;
        switch (n)
        {
        case 1:
            str = 'a';
            break;
        case 2:
            str = 'b';
            break;
        case 3:
            str = 'c';
            break;
        case 4:
            str = 'd';
            break;
        case 5:
            str = 'e';
            break;
        case 6:
            str = 'f';
            break;
        case 7:
            str = 'g';
            break;
        case 8:
            str = 'h';
            break;
        case 9:
            str = 'i';
            break;
        case 10:
            str = 'j';
            break;
        case 11:
            str = 'k';
            break;
        case 12:
            str = 'l';
            break;
        case 13:
            str = 'm';
            break;
        case 14:
            str = 'n';
            break;
        case 15:
            str = 'o';
            break;
        case 16:
            str = 'p';
            break;
        case 17:
            str = 'q';
            break;
        case 18:
            str = 'q';
            break;
        case 19:
            str = 'r';
            break;
        case 20:
            str = 's';
            break;
        case 21:
            str = 't';
            break;
        case 22:
            str = 'u';
            break;
        case 23:
            str = 'v';
            break;
        case 24:
            str = 'x';
            break;
        case 25:
            str = 'y';
            break;
        case 26:
            str = 'z';
            break;
        case 27:
            str = '1';
            break;
        case 28:
            str = '2';
            break;
        case 29:
            str = '3';
            break;
        case 30:
            str = '4';
            break;
        case 31:
            str = '5';
            break;
        case 32:
            str = '6';
            break;
        case 33:
            str = '7';
            break;
        case 34:
            str = '8';
            break;
        case 35:
            str = '9';
            break;
        case 36:
            str = '0';
            break;
        default:
            break;
        }
        return str;
    }

