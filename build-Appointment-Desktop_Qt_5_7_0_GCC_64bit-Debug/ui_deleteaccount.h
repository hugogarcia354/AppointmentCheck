/********************************************************************************
** Form generated from reading UI file 'deleteaccount.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEACCOUNT_H
#define UI_DELETEACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_deleteaccount
{
public:
    QGroupBox *groupBox;
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *password;

    void setupUi(QDialog *deleteaccount)
    {
        if (deleteaccount->objectName().isEmpty())
            deleteaccount->setObjectName(QStringLiteral("deleteaccount"));
        deleteaccount->resize(284, 253);
        groupBox = new QGroupBox(deleteaccount);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 281, 251));
        buttonBox = new QDialogButtonBox(groupBox);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(50, 200, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 70, 241, 61));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 140, 171, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 40, 221, 41));
        QFont font;
        font.setPointSize(29);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        password = new QLineEdit(groupBox);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(80, 170, 113, 22));

        retranslateUi(deleteaccount);
        QObject::connect(buttonBox, SIGNAL(accepted()), deleteaccount, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), deleteaccount, SLOT(reject()));

        QMetaObject::connectSlotsByName(deleteaccount);
    } // setupUi

    void retranslateUi(QDialog *deleteaccount)
    {
        deleteaccount->setWindowTitle(QApplication::translate("deleteaccount", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("deleteaccount", "Delete Account", 0));
        label->setText(QApplication::translate("deleteaccount", "You are about to delete your own account.", 0));
        label_2->setText(QApplication::translate("deleteaccount", "Enter password for Verification:", 0));
        label_3->setText(QApplication::translate("deleteaccount", "WARNING!", 0));
    } // retranslateUi

};

namespace Ui {
    class deleteaccount: public Ui_deleteaccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEACCOUNT_H
