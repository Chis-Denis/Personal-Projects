/********************************************************************************
** Form generated from reading UI file 'UserWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWINDOW_H
#define UI_USERWINDOW_H

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

class Ui_UserWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonGenre;
    QPushButton *pushButtonSee;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonDisplay;
    QListWidget *listWidget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QPushButton *pushButtonExit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UserWindow)
    {
        if (UserWindow->objectName().isEmpty())
            UserWindow->setObjectName("UserWindow");
        UserWindow->resize(800, 600);
        centralwidget = new QWidget(UserWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 10, 160, 281));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonGenre = new QPushButton(verticalLayoutWidget);
        pushButtonGenre->setObjectName("pushButtonGenre");

        verticalLayout->addWidget(pushButtonGenre);

        pushButtonSee = new QPushButton(verticalLayoutWidget);
        pushButtonSee->setObjectName("pushButtonSee");

        verticalLayout->addWidget(pushButtonSee);

        pushButtonSave = new QPushButton(verticalLayoutWidget);
        pushButtonSave->setObjectName("pushButtonSave");

        verticalLayout->addWidget(pushButtonSave);

        pushButtonDisplay = new QPushButton(verticalLayoutWidget);
        pushButtonDisplay->setObjectName("pushButtonDisplay");

        verticalLayout->addWidget(pushButtonDisplay);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(180, 40, 611, 192));
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(240, 420, 291, 80));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(verticalLayoutWidget_2);
        lineEdit->setObjectName("lineEdit");

        verticalLayout_2->addWidget(lineEdit);

        pushButtonExit = new QPushButton(verticalLayoutWidget_2);
        pushButtonExit->setObjectName("pushButtonExit");

        verticalLayout_2->addWidget(pushButtonExit);

        UserWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UserWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        UserWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(UserWindow);
        statusbar->setObjectName("statusbar");
        UserWindow->setStatusBar(statusbar);

        retranslateUi(UserWindow);

        QMetaObject::connectSlotsByName(UserWindow);
    } // setupUi

    void retranslateUi(QMainWindow *UserWindow)
    {
        UserWindow->setWindowTitle(QCoreApplication::translate("UserWindow", "MainWindow", nullptr));
        pushButtonGenre->setText(QCoreApplication::translate("UserWindow", "Dysplay Movies by genre", nullptr));
        pushButtonSee->setText(QCoreApplication::translate("UserWindow", "See watch list", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("UserWindow", "Save to file WatchList", nullptr));
        pushButtonDisplay->setText(QCoreApplication::translate("UserWindow", "Dysplay all movies", nullptr));
        pushButtonExit->setText(QCoreApplication::translate("UserWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWindow: public Ui_UserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
