#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLabel>
#include "ui_AdminUserWindow.h"
#include "AdminWindow.h"
#include "UserWindow.h"

class AdminUserWindow : public QMainWindow
{
    Q_OBJECT

public:
    AdminUserWindow(int optionForSave, QWidget* parent = nullptr);
    ~AdminUserWindow();

private slots:
    void on_pushButtonAdmin_clicked();
    void on_pushButtonUser_clicked();

private:
    int optionForSave;
    Ui::AdminUserWindow ui;
};

