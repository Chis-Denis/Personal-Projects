#pragma once
#include <string>
#include "Media.h"

class WatchList : public Media {
public:
    WatchList() : Media() {}
    WatchList(std::string title, std::string genre, int year, int likes, std::string trailer)
        : Media(title, genre, year, likes, trailer) {}

    void incrementLikes();
};
