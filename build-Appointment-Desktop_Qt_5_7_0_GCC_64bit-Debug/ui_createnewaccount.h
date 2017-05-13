/********************************************************************************
** Form generated from reading UI file 'createnewaccount.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATENEWACCOUNT_H
#define UI_CREATENEWACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_CreateNewAccount
{
public:
    QGroupBox *groupBox;
    QLineEdit *username;
    QLineEdit *password;
    QLineEdit *firstName;
    QLineEdit *lastName;
    QLineEdit *phone;
    QLineEdit *email;
    QComboBox *comboBox;
    QSplitter *splitter;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *CreateNewAccount)
    {
        if (CreateNewAccount->objectName().isEmpty())
            CreateNewAccount->setObjectName(QStringLiteral("CreateNewAccount"));
        CreateNewAccount->resize(400, 300);
        groupBox = new QGroupBox(CreateNewAccount);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(60, 10, 261, 211));
        username = new QLineEdit(groupBox);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(20, 30, 113, 22));
        password = new QLineEdit(groupBox);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(20, 60, 113, 22));
        password->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        firstName = new QLineEdit(groupBox);
        firstName->setObjectName(QStringLiteral("firstName"));
        firstName->setGeometry(QRect(20, 90, 113, 22));
        lastName = new QLineEdit(groupBox);
        lastName->setObjectName(QStringLiteral("lastName"));
        lastName->setGeometry(QRect(20, 120, 113, 22));
        phone = new QLineEdit(groupBox);
        phone->setObjectName(QStringLiteral("phone"));
        phone->setGeometry(QRect(20, 150, 161, 22));
        email = new QLineEdit(groupBox);
        email->setObjectName(QStringLiteral("email"));
        email->setGeometry(QRect(20, 180, 113, 22));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(180, 150, 72, 22));
        splitter = new QSplitter(CreateNewAccount);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(100, 240, 171, 22));
        splitter->setOrientation(Qt::Horizontal);
        pushButton = new QPushButton(splitter);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        font.setKerning(true);
        pushButton->setFont(font);
        pushButton->setAutoDefault(true);
        splitter->addWidget(pushButton);
        pushButton_2 = new QPushButton(splitter);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        splitter->addWidget(pushButton_2);
        QWidget::setTabOrder(username, password);
        QWidget::setTabOrder(password, firstName);
        QWidget::setTabOrder(firstName, lastName);
        QWidget::setTabOrder(lastName, phone);
        QWidget::setTabOrder(phone, comboBox);
        QWidget::setTabOrder(comboBox, email);
        QWidget::setTabOrder(email, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_2);

        retranslateUi(CreateNewAccount);
        QObject::connect(username, SIGNAL(editingFinished()), pushButton, SLOT(toggle()));
        QObject::connect(password, SIGNAL(editingFinished()), pushButton, SLOT(toggle()));
        QObject::connect(firstName, SIGNAL(editingFinished()), pushButton, SLOT(toggle()));
        QObject::connect(lastName, SIGNAL(editingFinished()), pushButton, SLOT(toggle()));
        QObject::connect(phone, SIGNAL(selectionChanged()), pushButton, SLOT(toggle()));
        QObject::connect(comboBox, SIGNAL(editTextChanged(QString)), pushButton, SLOT(toggle()));
        QObject::connect(email, SIGNAL(editingFinished()), pushButton, SLOT(toggle()));

        QMetaObject::connectSlotsByName(CreateNewAccount);
    } // setupUi

    void retranslateUi(QDialog *CreateNewAccount)
    {
        CreateNewAccount->setWindowTitle(QApplication::translate("CreateNewAccount", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("CreateNewAccount", "Create New Account", 0));
        username->setPlaceholderText(QApplication::translate("CreateNewAccount", "Username", 0));
        password->setPlaceholderText(QApplication::translate("CreateNewAccount", "Password", 0));
        firstName->setText(QString());
        firstName->setPlaceholderText(QApplication::translate("CreateNewAccount", "First Name", 0));
        lastName->setPlaceholderText(QApplication::translate("CreateNewAccount", "Last Name", 0));
        phone->setPlaceholderText(QApplication::translate("CreateNewAccount", "Phone Number (no dashes)", 0));
        email->setPlaceholderText(QApplication::translate("CreateNewAccount", "Email Address", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("CreateNewAccount", "Provider", 0)
         << QApplication::translate("CreateNewAccount", "Verizon", 0)
         << QApplication::translate("CreateNewAccount", "T-Mobile", 0)
         << QApplication::translate("CreateNewAccount", "Metro PCS", 0)
         << QApplication::translate("CreateNewAccount", "Sprint", 0)
        );
        pushButton->setText(QApplication::translate("CreateNewAccount", "Create Account", 0));
        pushButton_2->setText(QApplication::translate("CreateNewAccount", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateNewAccount: public Ui_CreateNewAccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATENEWACCOUNT_H
