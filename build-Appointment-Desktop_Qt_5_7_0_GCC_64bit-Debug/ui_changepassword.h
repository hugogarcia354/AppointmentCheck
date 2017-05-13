/********************************************************************************
** Form generated from reading UI file 'changepassword.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASSWORD_H
#define UI_CHANGEPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangePassword
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *current;
    QLineEdit *newpassword;
    QLineEdit *confirm;
    QLabel *label;

    void setupUi(QDialog *ChangePassword)
    {
        if (ChangePassword->objectName().isEmpty())
            ChangePassword->setObjectName(QStringLiteral("ChangePassword"));
        ChangePassword->resize(286, 275);
        buttonBox = new QDialogButtonBox(ChangePassword);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(50, 220, 181, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(ChangePassword);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 50, 141, 141));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        current = new QLineEdit(layoutWidget);
        current->setObjectName(QStringLiteral("current"));
        current->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(current);

        newpassword = new QLineEdit(layoutWidget);
        newpassword->setObjectName(QStringLiteral("newpassword"));
        newpassword->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(newpassword);

        confirm = new QLineEdit(layoutWidget);
        confirm->setObjectName(QStringLiteral("confirm"));
        confirm->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(confirm);

        label = new QLabel(ChangePassword);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 20, 181, 31));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label->setFont(font);

        retranslateUi(ChangePassword);
        QObject::connect(buttonBox, SIGNAL(accepted()), ChangePassword, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ChangePassword, SLOT(reject()));

        QMetaObject::connectSlotsByName(ChangePassword);
    } // setupUi

    void retranslateUi(QDialog *ChangePassword)
    {
        ChangePassword->setWindowTitle(QApplication::translate("ChangePassword", "Dialog", 0));
        current->setPlaceholderText(QApplication::translate("ChangePassword", "Current Password...", 0));
        newpassword->setPlaceholderText(QApplication::translate("ChangePassword", "New Password", 0));
        confirm->setPlaceholderText(QApplication::translate("ChangePassword", "Confirm New Password", 0));
        label->setText(QApplication::translate("ChangePassword", "Change Password", 0));
    } // retranslateUi

};

namespace Ui {
    class ChangePassword: public Ui_ChangePassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASSWORD_H
