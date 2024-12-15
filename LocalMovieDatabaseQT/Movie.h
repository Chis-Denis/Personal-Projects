#pragma once
#include <string>
#include "Media.h"
    
class Movie : public Media {
public:
    Movie() : Media() {}
    Movie(std::string title, std::string genre, int year, int likes, std::string trailer)
        : Media(title, genre, year, likes, trailer) {}

    // Additional methods specific to Movie, if any
};
