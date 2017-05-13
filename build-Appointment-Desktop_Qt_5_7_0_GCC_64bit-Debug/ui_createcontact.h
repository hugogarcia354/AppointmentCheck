/********************************************************************************
** Form generated from reading UI file 'createcontact.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECONTACT_H
#define UI_CREATECONTACT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateContact
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *firstName;
    QLineEdit *lastName;
    QHBoxLayout *horizontalLayout;
    QLineEdit *phone;
    QComboBox *comboBox;
    QLineEdit *email;

    void setupUi(QDialog *CreateContact)
    {
        if (CreateContact->objectName().isEmpty())
            CreateContact->setObjectName(QStringLiteral("CreateContact"));
        CreateContact->resize(306, 292);
        buttonBox = new QDialogButtonBox(CreateContact);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(50, 230, 181, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(CreateContact);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(18, 20, 251, 201));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 50, 190, 110));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        firstName = new QLineEdit(layoutWidget);
        firstName->setObjectName(QStringLiteral("firstName"));

        verticalLayout->addWidget(firstName);

        lastName = new QLineEdit(layoutWidget);
        lastName->setObjectName(QStringLiteral("lastName"));

        verticalLayout->addWidget(lastName);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        phone = new QLineEdit(layoutWidget);
        phone->setObjectName(QStringLiteral("phone"));

        horizontalLayout->addWidget(phone);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);

        email = new QLineEdit(layoutWidget);
        email->setObjectName(QStringLiteral("email"));

        verticalLayout->addWidget(email);

        QWidget::setTabOrder(firstName, lastName);
        QWidget::setTabOrder(lastName, phone);
        QWidget::setTabOrder(phone, comboBox);
        QWidget::setTabOrder(comboBox, email);

        retranslateUi(CreateContact);
        QObject::connect(buttonBox, SIGNAL(accepted()), CreateContact, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CreateContact, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreateContact);
    } // setupUi

    void retranslateUi(QDialog *CreateContact)
    {
        CreateContact->setWindowTitle(QApplication::translate("CreateContact", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("CreateContact", "Create New Contact", 0));
        firstName->setPlaceholderText(QApplication::translate("CreateContact", "First Name", 0));
        lastName->setPlaceholderText(QApplication::translate("CreateContact", "Last Name", 0));
        phone->setPlaceholderText(QApplication::translate("CreateContact", "Phone Number", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("CreateContact", "Provider", 0)
         << QApplication::translate("CreateContact", "Verizon", 0)
         << QApplication::translate("CreateContact", "T-Mobile", 0)
         << QApplication::translate("CreateContact", "Metro PCS", 0)
         << QApplication::translate("CreateContact", "Sprint", 0)
        );
        email->setPlaceholderText(QApplication::translate("CreateContact", "Email", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateContact: public Ui_CreateContact {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECONTACT_H
