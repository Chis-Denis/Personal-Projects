#include "UserWindow.h"
#include <QFile>


UserWindow::UserWindow(int optionForSave, QWidget* parent)
    : QMainWindow(parent), optionForSave(optionForSave)
{
    ui.setupUi(this);
}

UserWindow::~UserWindow()
{}

//it makes a new window appear with the movies from the genre selected by the user one by one and the buttons: next, add to watchlist, stop
// //if no input is given, similary to the previous function, but with all the movies
//if the genre is invalid, display a message in a new window created by you
//when it reaches the end, it starts from the beginning
void UserWindow::on_pushButtonGenre_clicked()
{
    QString Input = ui.lineEdit->text();
	std::string input = Input.toStdString();
	std::vector<Movie> movies;
    if (input == "")
    {
		movies = service.getAllMoviesService();
	}
    else
    {
		movies = service.getMoviesByGenreService(input);
	}
    if (movies.empty())
    {
		QWidget* window = new QWidget;
		QLabel* label = new QLabel("Invalid input!", window);
		window->setFixedSize(300, 300);
		QVBoxLayout* layout = new QVBoxLayout(window);
		layout->addWidget(label);
		window->setLayout(layout);
		window->show();
	}
    else
    {

		GenreWindow* genreWindow = new GenreWindow(service);
        std::string trailer = movies[0].getTrailer();
        service.watchTrailerService(trailer);
		genreWindow->setGenreList(movies);
		genreWindow->show();
	}
	service.cleanup();
}

//see watchlist
//if it is empty, display a message in a new window created by you
//else create a new window, display the watchlist in a created list widget and create 4 buttons under the list: like, next, delete, stop
//in the watchlist, the movies are displayed one by one and when it reaches the end, it starts from the beginning
//create the buttons and implement the functionality for them
void UserWindow::on_pushButtonSee_clicked()
{
    ui.listWidget->clear();
    std::vector<WatchList> watch_list = service.seeWatchListService();
    if (watch_list.empty())
    {
        QWidget* window = new QWidget;
        QLabel* label = new QLabel("WatchList empty", window);
        window->setFixedSize(300, 300);
        QVBoxLayout* layout = new QVBoxLayout(window);
        layout->addWidget(label);
        window->setLayout(layout);
        window->show();
    }
    else
    {
        WatchListWindow* watchListWindow = new WatchListWindow(service);
        watchListWindow->setWatchList(watch_list);
        watchListWindow->show();
        service.cleanup();
    }
}

void UserWindow::on_pushButtonDisplay_clicked()
{
	ui.listWidget->clear();
	std::vector<Movie> movies = service.getAllMoviesService();
	for (auto movie : movies)
	{
		QString item = QString::fromStdString(movie.getTitle() + " - " + movie.getGenre() + " - " + std::to_string(movie.getYear()) + " - " + std::to_string(movie.getLikes()) + " - " + movie.getTrailer());
		ui.listWidget->addItem(item);
	}
}

void UserWindow::on_pushButtonSave_clicked()
{
	service.saveToFileWatchListService(this->optionForSave);
}

void UserWindow::on_pushButtonExit_clicked()
{
    service.cleanup();
	this->close();
}