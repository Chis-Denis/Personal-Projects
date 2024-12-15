#include "AdminWindow.h"
#include <QFile>


AdminWindow::AdminWindow(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}


AdminWindow::~AdminWindow()
{}

//add a movie from the same line edit through one input
void AdminWindow::on_pushButtonAdd_clicked()
{
	QString Input = ui.lineEdit->text();
	std::string input = Input.toStdString();

	//if the input is invalid, pop an error message in a new window with a fixed size
	//there is not an QMessageBox
	bool test = service.addMovieService(input);
	if (test == false)
	{
		QWidget* window = new QWidget;
		QLabel* label = new QLabel("Invalid input!", window);
		window->setFixedSize(300, 300);
		window->show();
	}
	ui.lineEdit->clear();
	on_pushButtonDisplay_clicked();
}

void AdminWindow::on_pushButtonUpdate_clicked()
{
	QString Input = ui.lineEdit->text();
	std::string input = Input.toStdString();
	bool test = service.updateMovieService(input);
	if (test == false)
	{
		QWidget* window = new QWidget;
		QLabel* label = new QLabel("Invalid input!", window);
		window->setFixedSize(300, 300);
		window->show();
	}
	ui.lineEdit->clear();
	on_pushButtonDisplay_clicked();
}

void AdminWindow::on_pushButtonDelete_clicked()
{
	QString Input = ui.lineEdit->text();
	std::string input = Input.toStdString();
	bool test = service.deleteMovieService(input);
	if (test == false)
	{
		QWidget* window = new QWidget;
		QLabel* label = new QLabel("Invalid input!", window);
		window->setFixedSize(300, 300);
		window->show();
	}
	ui.lineEdit->clear();
	on_pushButtonDisplay_clicked();
}

void AdminWindow::on_pushButtonDisplay_clicked()
{
    ui.listWidget->clear();
	std::vector<Movie> movies = service.getAllMoviesService();
	for (auto movie : movies)
	{
		QString item = QString::fromStdString(movie.getTitle() + " - " + movie.getGenre() + " - " + std::to_string(movie.getYear()) + " - " + std::to_string(movie.getLikes()) + " - " + movie.getTrailer());
		ui.listWidget->addItem(item);
	}
}

//undo the last operation
void AdminWindow::on_pushButtonUndo_clicked()
{
	service.undo();
	on_pushButtonDisplay_clicked();
}

void AdminWindow::on_pushButtonRedo_clicked()
{
	service.redo();
	on_pushButtonDisplay_clicked();
}

void AdminWindow::on_pushButtonExit_clicked()
{
	service.cleanup();
	this->close();
}