#include "WatchListWindow.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>

WatchListWindow::WatchListWindow(Service& service, QWidget* parent)
    : QWidget(parent), service(service), currentIndex(0)
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    listWidget = new QListWidget(this);
    mainLayout->addWidget(listWidget);

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    likeButton = new QPushButton("Like", this);
    nextButton = new QPushButton("Next", this);
    deleteButton = new QPushButton("Delete", this);
    stopButton = new QPushButton("Stop", this);

    buttonLayout->addWidget(likeButton);
    buttonLayout->addWidget(nextButton);
    buttonLayout->addWidget(deleteButton);
    buttonLayout->addWidget(stopButton);

    mainLayout->addLayout(buttonLayout);

    connect(likeButton, &QPushButton::clicked, this, &WatchListWindow::onLikeClicked);
    connect(nextButton, &QPushButton::clicked, this, &WatchListWindow::onNextClicked);
    connect(deleteButton, &QPushButton::clicked, this, &WatchListWindow::onDeleteClicked);
    connect(stopButton, &QPushButton::clicked, this, &WatchListWindow::onStopClicked);
}

void WatchListWindow::setWatchList(const std::vector<WatchList>& watch_list)
{
    watchList = watch_list;
    currentIndex = 0;
    listWidget->clear();
    if (!watchList.empty())
    {
        auto& wl = watchList[currentIndex];
        QString item = QString::fromStdString(wl.getTitle() + " - " + wl.getGenre() + " - " + std::to_string(wl.getYear()) + " - " + std::to_string(wl.getLikes()) + " - " + wl.getTrailer());
        listWidget->addItem(item);
    }
}

void WatchListWindow::onLikeClicked()
{
    if (currentIndex < watchList.size())
    {
        service.likeMovieService(watchList[currentIndex]);
        listWidget->clear();
        //listWidget->currentItem()->setText(QString::fromStdString(watchList[currentIndex].getTitle() + " - " + watchList[currentIndex].getGenre() + " - " + std::to_string(watchList[currentIndex].getYear()) + " - " + std::to_string(watchList[currentIndex].getLikes()) + " - " + watchList[currentIndex].getTrailer()));
    }
}

void WatchListWindow::onNextClicked()
{
    if (!watchList.empty())
    {
        currentIndex = (currentIndex + 1) % watchList.size();
        listWidget->clear();
        auto& wl = watchList[currentIndex];
        QString item = QString::fromStdString(wl.getTitle() + " - " + wl.getGenre() + " - " + std::to_string(wl.getYear()) + " - " + std::to_string(wl.getLikes()) + " - " + wl.getTrailer());
        listWidget->addItem(item);
    }
}

void WatchListWindow::onDeleteClicked()
{
    if (currentIndex < watchList.size())
    {
        service.deleteMovieFromWatchListService(watchList[currentIndex]);
        watchList.erase(watchList.begin() + currentIndex);
        if (watchList.empty())
        {
            listWidget->clear();
            return;
        }
        currentIndex = currentIndex % watchList.size();
        listWidget->clear();
        auto& wl = watchList[currentIndex];
        QString item = QString::fromStdString(wl.getTitle() + " - " + wl.getGenre() + " - " + std::to_string(wl.getYear()) + " - " + std::to_string(wl.getLikes()) + " - " + wl.getTrailer());
        listWidget->addItem(item);
    }
}

void WatchListWindow::onStopClicked()
{
    service.cleanup();
    close();
}
