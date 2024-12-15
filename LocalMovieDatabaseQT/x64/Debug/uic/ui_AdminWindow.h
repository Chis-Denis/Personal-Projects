/********************************************************************************
** Form generated from reading UI file 'AdminWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonDelete;
    QPushButton *pushButtonUpdate;
    QPushButton *pushButtonDisplay;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QPushButton *pushButtonExit;
    QListWidget *listWidget;
    QPushButton *pushButtonUndo;
    QPushButton *pushButtonRedo;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName("AdminWindow");
        AdminWindow->resize(641, 482);
        centralwidget = new QWidget(AdminWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 131, 231));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonAdd = new QPushButton(verticalLayoutWidget);
        pushButtonAdd->setObjectName("pushButtonAdd");

        verticalLayout->addWidget(pushButtonAdd);

        pushButtonDelete = new QPushButton(verticalLayoutWidget);
        pushButtonDelete->setObjectName("pushButtonDelete");

        verticalLayout->addWidget(pushButtonDelete);

        pushButtonUpdate = new QPushButton(verticalLayoutWidget);
        pushButtonUpdate->setObjectName("pushButtonUpdate");

        verticalLayout->addWidget(pushButtonUpdate);

        pushButtonDisplay = new QPushButton(verticalLayoutWidget);
        pushButtonDisplay->setObjectName("pushButtonDisplay");

        verticalLayout->addWidget(pushButtonDisplay);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(160, 350, 301, 80));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(verticalLayoutWidget_2);
        lineEdit->setObjectName("lineEdit");

        verticalLayout_2->addWidget(lineEdit);

        pushButtonExit = new QPushButton(verticalLayoutWidget_2);
        pushButtonExit->setObjectName("pushButtonExit");

        verticalLayout_2->addWidget(pushButtonExit);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(140, 20, 501, 192));
        pushButtonUndo = new QPushButton(centralwidget);
        pushButtonUndo->setObjectName("pushButtonUndo");
        pushButtonUndo->setGeometry(QRect(20, 400, 80, 24));
        pushButtonRedo = new QPushButton(centralwidget);
        pushButtonRedo->setObjectName("pushButtonRedo");
        pushButtonRedo->setGeometry(QRect(550, 400, 80, 24));
        AdminWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdminWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 641, 21));
        AdminWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AdminWindow);
        statusbar->setObjectName("statusbar");
        AdminWindow->setStatusBar(statusbar);

        retranslateUi(AdminWindow);

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminWindow)
    {
        AdminWindow->setWindowTitle(QCoreApplication::translate("AdminWindow", "MainWindow", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("AdminWindow", "Add", nullptr));
        pushButtonDelete->setText(QCoreApplication::translate("AdminWindow", "Delete", nullptr));
        pushButtonUpdate->setText(QCoreApplication::translate("AdminWindow", "Update", nullptr));
        pushButtonDisplay->setText(QCoreApplication::translate("AdminWindow", "Display All", nullptr));
        pushButtonExit->setText(QCoreApplication::translate("AdminWindow", "Exit", nullptr));
        pushButtonUndo->setText(QCoreApplication::translate("AdminWindow", "Undo", nullptr));
        pushButtonRedo->setText(QCoreApplication::translate("AdminWindow", "Redo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
