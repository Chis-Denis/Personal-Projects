/********************************************************************************
** Form generated from reading UI file 'AdminUserWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINUSERWINDOW_H
#define UI_ADMINUSERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminUserWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonUser;
    QPushButton *pushButtonAdmin;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminUserWindow)
    {
        if (AdminUserWindow->objectName().isEmpty())
            AdminUserWindow->setObjectName("AdminUserWindow");
        AdminUserWindow->resize(608, 406);
        centralwidget = new QWidget(AdminUserWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButtonUser = new QPushButton(centralwidget);
        pushButtonUser->setObjectName("pushButtonUser");

        horizontalLayout->addWidget(pushButtonUser);

        pushButtonAdmin = new QPushButton(centralwidget);
        pushButtonAdmin->setObjectName("pushButtonAdmin");

        horizontalLayout->addWidget(pushButtonAdmin);


        horizontalLayout_2->addLayout(horizontalLayout);

        AdminUserWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdminUserWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 608, 21));
        AdminUserWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AdminUserWindow);
        statusbar->setObjectName("statusbar");
        AdminUserWindow->setStatusBar(statusbar);

        retranslateUi(AdminUserWindow);

        QMetaObject::connectSlotsByName(AdminUserWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminUserWindow)
    {
        AdminUserWindow->setWindowTitle(QCoreApplication::translate("AdminUserWindow", "MainWindow", nullptr));
        pushButtonUser->setText(QCoreApplication::translate("AdminUserWindow", "User", nullptr));
        pushButtonAdmin->setText(QCoreApplication::translate("AdminUserWindow", "Admin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminUserWindow: public Ui_AdminUserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINUSERWINDOW_H
