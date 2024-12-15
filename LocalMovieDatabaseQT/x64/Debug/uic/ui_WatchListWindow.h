/********************************************************************************
** Form generated from reading UI file 'WatchListWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WATCHLISTWINDOW_H
#define UI_WATCHLISTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WatchListWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WatchListWindow)
    {
        if (WatchListWindow->objectName().isEmpty())
            WatchListWindow->setObjectName("WatchListWindow");
        WatchListWindow->resize(800, 600);
        centralwidget = new QWidget(WatchListWindow);
        centralwidget->setObjectName("centralwidget");
        WatchListWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WatchListWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        WatchListWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(WatchListWindow);
        statusbar->setObjectName("statusbar");
        WatchListWindow->setStatusBar(statusbar);

        retranslateUi(WatchListWindow);

        QMetaObject::connectSlotsByName(WatchListWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WatchListWindow)
    {
        WatchListWindow->setWindowTitle(QCoreApplication::translate("WatchListWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WatchListWindow: public Ui_WatchListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WATCHLISTWINDOW_H
