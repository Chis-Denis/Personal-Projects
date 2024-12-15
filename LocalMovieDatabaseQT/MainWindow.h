#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLabel>
#include "ui_MainWindow.h"
#include "AdminUserWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
	void on_pushButtonHTML_clicked();
    void on_pushButtonCSV_clicked();

private:
    int optionForSave;
    Ui::MainWindowClass ui;
};

