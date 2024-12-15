#pragma once

#include "Repository.h"
#include "Utils.h"
#include <string>

class Service
{
private:
    Repository repo;
    std::string filename;

public:
    Service();
    ~Service();
    // void addExMoviesService();

     // Modify other methods as needed to use repo methods provided by Repository

    bool addMovieService(std::string& input);
    bool deleteMovieService(std::string& title);
    bool updateMovieService(std::string& input);
    std::vector<Movie> getAllMoviesService();
    std::vector<Movie> getMoviesByGenreService(std::string& genre);
    void watchTrailerService(const std::string& title);
    std::vector<WatchList> seeWatchListService();
    std::vector<WatchList> addMovieToWatchListService(Movie& movie_to_add);
    void likeMovieService(WatchList& movie);
    void deleteMovieFromWatchListService(WatchList& movie);

    //void initialRead();

    void saveToFileWatchListService(int optionForSave);

    void undo();
    void redo();
    void cleanup();

};