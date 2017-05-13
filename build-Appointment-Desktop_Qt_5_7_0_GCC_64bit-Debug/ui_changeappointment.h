/********************************************************************************
** Form generated from reading UI file 'changeappointment.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEAPPOINTMENT_H
#define UI_CHANGEAPPOINTMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangeAppointment
{
public:
    QTableView *AppointmentView;
    QCalendarWidget *calendarWidget;
    QTimeEdit *timeEdit;
    QDateEdit *dateEdit;
    QPushButton *update;
    QPushButton *close;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QLabel *currentContact;
    QLabel *currentDate;
    QLabel *currentUser;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_s;
    QLabel *newContact;
    QLabel *newDate;
    QLabel *newUser;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *userBox;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QComboBox *contactList;

    void setupUi(QDialog *ChangeAppointment)
    {
        if (ChangeAppointment->objectName().isEmpty())
            ChangeAppointment->setObjectName(QStringLiteral("ChangeAppointment"));
        ChangeAppointment->resize(580, 381);
        AppointmentView = new QTableView(ChangeAppointment);
        AppointmentView->setObjectName(QStringLiteral("AppointmentView"));
        AppointmentView->setGeometry(QRect(0, 0, 221, 241));
        AppointmentView->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        calendarWidget = new QCalendarWidget(ChangeAppointment);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(240, 0, 304, 181));
        calendarWidget->setGridVisible(true);
        calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        calendarWidget->setNavigationBarVisible(true);
        calendarWidget->setDateEditEnabled(true);
        timeEdit = new QTimeEdit(ChangeAppointment);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setGeometry(QRect(430, 180, 118, 23));
        dateEdit = new QDateEdit(ChangeAppointment);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(280, 180, 110, 23));
        update = new QPushButton(ChangeAppointment);
        update->setObjectName(QStringLiteral("update"));
        update->setEnabled(false);
        update->setGeometry(QRect(330, 330, 80, 22));
        close = new QPushButton(ChangeAppointment);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(430, 330, 80, 22));
        layoutWidget = new QWidget(ChangeAppointment);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(230, 250, 322, 78));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setEnabled(true);
        QFont font;
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label_6->setFont(font);

        verticalLayout->addWidget(label_6);

        currentContact = new QLabel(layoutWidget);
        currentContact->setObjectName(QStringLiteral("currentContact"));

        verticalLayout->addWidget(currentContact);

        currentDate = new QLabel(layoutWidget);
        currentDate->setObjectName(QStringLiteral("currentDate"));

        verticalLayout->addWidget(currentDate);

        currentUser = new QLabel(layoutWidget);
        currentUser->setObjectName(QStringLiteral("currentUser"));

        verticalLayout->addWidget(currentUser);


        horizontalLayout->addLayout(verticalLayout);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        horizontalLayout->addWidget(label_8);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_s = new QLabel(layoutWidget);
        label_s->setObjectName(QStringLiteral("label_s"));
        label_s->setFont(font);

        verticalLayout_2->addWidget(label_s);

        newContact = new QLabel(layoutWidget);
        newContact->setObjectName(QStringLiteral("newContact"));

        verticalLayout_2->addWidget(newContact);

        newDate = new QLabel(layoutWidget);
        newDate->setObjectName(QStringLiteral("newDate"));

        verticalLayout_2->addWidget(newDate);

        newUser = new QLabel(layoutWidget);
        newUser->setObjectName(QStringLiteral("newUser"));

        verticalLayout_2->addWidget(newUser);


        horizontalLayout->addLayout(verticalLayout_2);

        layoutWidget1 = new QWidget(ChangeAppointment);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(240, 210, 151, 24));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        userBox = new QComboBox(layoutWidget1);
        userBox->setObjectName(QStringLiteral("userBox"));
        userBox->setEnabled(false);

        horizontalLayout_2->addWidget(userBox);

        layoutWidget2 = new QWidget(ChangeAppointment);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(410, 210, 136, 24));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setPointSize(11);
        label->setFont(font1);

        horizontalLayout_3->addWidget(label);

        contactList = new QComboBox(layoutWidget2);
        contactList->setObjectName(QStringLiteral("contactList"));

        horizontalLayout_3->addWidget(contactList);


        retranslateUi(ChangeAppointment);
        QObject::connect(calendarWidget, SIGNAL(clicked(QDate)), dateEdit, SLOT(setDate(QDate)));
        QObject::connect(dateEdit, SIGNAL(dateChanged(QDate)), calendarWidget, SLOT(setSelectedDate(QDate)));

        QMetaObject::connectSlotsByName(ChangeAppointment);
    } // setupUi

    void retranslateUi(QDialog *ChangeAppointment)
    {
        ChangeAppointment->setWindowTitle(QApplication::translate("ChangeAppointment", "Dialog", 0));
        update->setText(QApplication::translate("ChangeAppointment", "Update", 0));
        close->setText(QApplication::translate("ChangeAppointment", "Close", 0));
        label_6->setText(QApplication::translate("ChangeAppointment", "Current Appointment:", 0));
        currentContact->setText(QApplication::translate("ChangeAppointment", "Contact Name:", 0));
        currentDate->setText(QApplication::translate("ChangeAppointment", "Date and Time:", 0));
        currentUser->setText(QString());
        label_8->setText(QApplication::translate("ChangeAppointment", "Change to ->", 0));
        label_s->setText(QApplication::translate("ChangeAppointment", "New Appointment:", 0));
        newContact->setText(QApplication::translate("ChangeAppointment", "Contact Name:", 0));
        newDate->setText(QApplication::translate("ChangeAppointment", "Date and Time:", 0));
        newUser->setText(QString());
        label_2->setText(QApplication::translate("ChangeAppointment", "Username:", 0));
        label->setText(QApplication::translate("ChangeAppointment", "Contact:", 0));
    } // retranslateUi

};

namespace Ui {
    class ChangeAppointment: public Ui_ChangeAppointment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEAPPOINTMENT_H
