#pragma once
#include <string>

class Media {
protected:
    std::string title;
    std::string genre;
    int year;
    int likes;
    std::string trailer;

public:
    Media() : title(""), genre(""), year(0), likes(0), trailer("") {}
    Media(std::string title, std::string genre, int year, int likes, std::string trailer)
        : title(title), genre(genre), year(year), likes(likes), trailer(trailer) {}

    std::string getTitle() const { return title; }
    std::string getGenre() const { return genre; }
    int getYear() const { return year; }
    int getLikes() const { return likes; }
    std::string getTrailer() const { return trailer; }

    void setTitle(const std::string& title) { this->title = title; }
    void setGenre(const std::string& genre) { this->genre = genre; }
    void setYear(int year) { this->year = year; }
    void setLikes(int likes) { this->likes = likes; }
    void setTrailer(const std::string& trailer) { this->trailer = trailer; }
};
