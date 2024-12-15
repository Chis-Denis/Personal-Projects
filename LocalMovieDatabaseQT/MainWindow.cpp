#include "MainWindow.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this -> optionForSave = 0;
}

MainWindow::~MainWindow()
{}

//save the oprion and then open AdminUserWindow and close MainWindow
void MainWindow::on_pushButtonHTML_clicked()
{
    this -> optionForSave = 1;
    AdminUserWindow* adminUserWindow = new AdminUserWindow(optionForSave);
    adminUserWindow -> show();
    this -> close();
}

void MainWindow::on_pushButtonCSV_clicked()
{
    this -> optionForSave = 2;
    AdminUserWindow* adminUserWindow = new AdminUserWindow(optionForSave);
    adminUserWindow -> show();
    this -> close();
}

//this is the settings.txt file
/*The Dark Knight, meh, 2008, 100,https://www.youtube.com/watch?v=EXeTwQWrcwY
Inception, action, 2010, 100,https://www.youtube.com/watch?v=YoHD9XEInc0
The Matrix, action, 1999, 100,https://www.youtube.com/watch?v=vKQi3bBA1y8
The Lord of the Rings: The Return of the King, action, 2003, 100,https://www.youtube.com/watch?v=r5X-hFf6Bwo
The Lord of the Rings: The Fellowship of the Ring, action, 2001, 100,https://www.youtube.com/watch?v=Pki6jbSbXIY
The Lord of the Rings: The Two Towers, action, 2002, 100,https://www.youtube.com/watch?v=LbfMDwc4azU
The Shawshank Redemption, action, 1994, 100,https://www.youtube.com/watch?v=6hB3S9bIaco
The Godfather, meh, 1972, 100,https://www.youtube.com/watch?v=sY1S34973zA
The Godfather: Part II, action, 1974, 100,https://www.youtube.com/watch?v=9O1Iy9od7-A
The Dark Knight Rises, COMEDY, 2012, 100,https://www.youtube.com/watch?v=g8evyE9TuYk
*/