#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <vector>
#include "ui_UserWindow.h"
#include "Service.h"

class GenreWindow : public QWidget
{
    Q_OBJECT

public:
    GenreWindow(Service& service, QWidget* parent = nullptr);
    void setGenreList(const std::vector<Movie>& watch_list);

private slots:
    void onAddClicked();
    void onNextClicked();
    void onStopClicked();

private:
    Service& service;
    QListWidget* listWidget;
    QPushButton* addButton;
    QPushButton* nextButton;
    QPushButton* stopButton;
    std::vector<Movie> movies;
    int currentIndex;
};
