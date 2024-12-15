#pragma once

#include "WatchList.h"
#include "Movie.h"
#include "Exceptions.h"
#include <vector>
#include <string>

class Repository
{
private:
    std::vector<Movie> movies;
    std::vector<WatchList> watch_list;
    std::string file_name;
    std::string file_name_watch_list;

public:

    Repository();
    ~Repository();

    bool addMovieRepository(Movie& movie_to_add);
    bool deleteMovieRepository(std::string& title);
    bool updateMovieRepository(Movie& movie, std::string& title_to_update, std::string& genre_to_update);
    std::vector<Movie> getMoviesByGenreRepository(std::string& genre);

    std::vector<WatchList> seeWatchListRepository();
    std::vector<WatchList> addMovieToWatchListRepository(Movie& movie_to_add);
    void likeMovieRepository(WatchList& movie);
    void deleteMovieFromWatchListRepository(WatchList& movie);

    std::vector<Movie> getMovies();

    void ReadWatchListFromFile();
    void WriteWatchListToFile();

    void readFromFile();
    void writeToFile();

    void saveToFileWatchListRepository(int optionForSave);

    void undo();
    void redo();
};