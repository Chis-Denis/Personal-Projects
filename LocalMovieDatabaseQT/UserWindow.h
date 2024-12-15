#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLabel>
#include "ui_UserWindow.h"
#include "Service.h"
#include "WatchListWindow.h"
#include "GenreWindow.h"


class UserWindow : public QMainWindow
{
    Q_OBJECT

public:
    UserWindow(int optionForSave, QWidget* parent = nullptr);
    ~UserWindow();

private slots:

	void on_pushButtonGenre_clicked();
	void on_pushButtonSee_clicked();
	void on_pushButtonDisplay_clicked();
	void on_pushButtonSave_clicked();
	void on_pushButtonExit_clicked();

private:
	int optionForSave;
    Service service;
    Ui::UserWindow ui;
};

