#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <vector>
#include "ui_UserWindow.h"
#include "Service.h"

class WatchListWindow : public QWidget
{
    Q_OBJECT

public:
    WatchListWindow(Service& service, QWidget* parent = nullptr);
    void setWatchList(const std::vector<WatchList>& watch_list);

private slots:
    void onLikeClicked();
    void onNextClicked();
    void onDeleteClicked();
    void onStopClicked();

private:
    Service& service;
    QListWidget* listWidget;
    QPushButton* likeButton;
    QPushButton* nextButton;
    QPushButton* deleteButton;
    QPushButton* stopButton;
    std::vector<WatchList> watchList;
    int currentIndex;
};
