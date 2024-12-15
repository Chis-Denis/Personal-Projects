#include "GenreWindow.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>

GenreWindow::GenreWindow(Service& service, QWidget* parent)
    : QWidget(parent), service(service), currentIndex(0)
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    listWidget = new QListWidget(this);
    mainLayout->addWidget(listWidget);

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    addButton = new QPushButton("Add", this);
    nextButton = new QPushButton("Next", this);
    stopButton = new QPushButton("Stop", this);

    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(nextButton);
    buttonLayout->addWidget(stopButton);

    mainLayout->addLayout(buttonLayout);

    connect(addButton, &QPushButton::clicked, this, &GenreWindow::onAddClicked);
    connect(nextButton, &QPushButton::clicked, this, &GenreWindow::onNextClicked);
    connect(stopButton, &QPushButton::clicked, this, &GenreWindow::onStopClicked);
}

void GenreWindow::setGenreList(const std::vector<Movie>& movies)
{
    this->movies = movies;
	currentIndex = 0;
	listWidget->clear();
    if (!movies.empty())
    {
		auto& wl = movies[currentIndex];
		QString item = QString::fromStdString(wl.getTitle() + " - " + wl.getGenre() + " - " + std::to_string(wl.getYear()) + " - " + std::to_string(wl.getLikes()) + " - " + wl.getTrailer());
		listWidget->addItem(item);
	}
}

//adds a movie to the watchlist
void GenreWindow::onAddClicked()
{
    if (currentIndex < movies.size())
    {
		service.addMovieToWatchListService(movies[currentIndex]);
		listWidget->clear();
	}
}

//displays the next movie in the user genre list
void GenreWindow::onNextClicked()
{
    if (!movies.empty())
    {
		currentIndex = (currentIndex + 1) % movies.size();
		listWidget->clear();
		auto& wl = movies[currentIndex];
        std::string trailer = wl.getTrailer();
        service.watchTrailerService(trailer);
		QString item = QString::fromStdString(wl.getTitle() + " - " + wl.getGenre() + " - " + std::to_string(wl.getYear()) + " - " + std::to_string(wl.getLikes()) + " - " + wl.getTrailer());
		listWidget->addItem(item);
	}
}

//stops the movie display
void GenreWindow::onStopClicked()
{
    service.cleanup();
    close();
}
