#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLabel>
#include "ui_AdminWindow.h"
#include "Service.h"

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    AdminWindow(QWidget* parent = nullptr);
    ~AdminWindow();

private slots:
    void on_pushButtonAdd_clicked();
    void on_pushButtonUpdate_clicked();
    void on_pushButtonDelete_clicked();
    void on_pushButtonDisplay_clicked();
    void on_pushButtonUndo_clicked();
    void on_pushButtonRedo_clicked();
    void on_pushButtonExit_clicked();

private:
    Service service;
    Ui::AdminWindow ui;
};