#include "AdminUserWindow.h"
#include <QFile>


AdminUserWindow::AdminUserWindow(int optionForSave, QWidget* parent)
    : QMainWindow(parent), optionForSave(optionForSave)
{
    ui.setupUi(this);
}

AdminUserWindow::~AdminUserWindow()
{}

void AdminUserWindow::on_pushButtonUser_clicked()
{
    UserWindow* userWindow = new UserWindow(optionForSave);
	userWindow->show();
	this->close();
}

//open the admin window
void AdminUserWindow::on_pushButtonAdmin_clicked()
{
    AdminWindow* adminWindow = new AdminWindow();
	adminWindow->show();
	this->close();
}