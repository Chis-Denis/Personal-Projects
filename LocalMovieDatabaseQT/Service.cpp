#include "Service.h"
#include <string>
#include <iostream>
#include <windows.h>
#include <shellapi.h>
#include <vector>

Service::Service() {}

Service::~Service() {}

/*void Service::addExMoviesService()
{
    Movie entryMovie1("The Dark Knight", "meh", 2008, 100, "https://www.youtube.com/watch?v=EXeTwQWrcwY");
    Movie entryMovie2("Inception", "action", 2010, 100, "https://www.youtube.com/watch?v=YoHD9XEInc0");
    Movie entryMovie3("The Matrix", "action", 1999, 100, "https://www.youtube.com/watch?v=vKQi3bBA1y8");
    Movie entryMovie4("The Lord of the Rings: The Return of the King", "action", 2003, 100, "https://www.youtube.com/watch?v=r5X-hFf6Bwo");
    Movie entryMovie5("The Lord of the Rings: The Fellowship of the Ring", "action", 2001, 100, "https://www.youtube.com/watch?v=Pki6jbSbXIY");
    Movie entryMovie6("The Lord of the Rings: The Two Towers", "action", 2002, 100, "https://www.youtube.com/watch?v=LbfMDwc4azU");
    Movie entryMovie7("The Shawshank Redemption", "action", 1994, 100, "https://www.youtube.com/watch?v=6hB3S9bIaco");
    Movie entryMovie8("The Godfather", "meh", 1972, 100, "https://www.youtube.com/watch?v=sY1S34973zA");
    Movie entryMovie9("The Godfather: Part II", "action", 1974, 100, "https://www.youtube.com/watch?v=9O1Iy9od7-A");
    Movie entryMovie10("The Dark Knight Rises", "action", 2012, 100, "https://www.youtube.com/watch?v=g8evyE9TuYk");

    repo.addMovieRepository(entryMovie1);
    repo.addMovieRepository(entryMovie2);
    repo.addMovieRepository(entryMovie3);
    repo.addMovieRepository(entryMovie4);
    repo.addMovieRepository(entryMovie5);
    repo.addMovieRepository(entryMovie6);
    repo.addMovieRepository(entryMovie7);
    repo.addMovieRepository(entryMovie8);
    repo.addMovieRepository(entryMovie9);
    repo.addMovieRepository(entryMovie10);
}*/

bool Service::addMovieService(std::string& input)
{
    trim(input);
    std::vector<std::string> tokens = tokenize(input, ',');
    if (tokens.size() != 5)
		return false;
    Movie movie(trim(tokens[0]), trim(tokens[1]), std::stoi(tokens[2]), std::stoi(tokens[3]), trim(tokens[4]));
	return repo.addMovieRepository(movie);
}

bool Service::deleteMovieService(std::string& title)
{
    return repo.deleteMovieRepository(title);
}

//the first two tokens are the title and genre of the movie to update and the rest are the new values
bool Service::updateMovieService(std::string& input)
{
    trim(input);
	std::vector<std::string> tokens = tokenize(input, ',');
	if (tokens.size() != 7)
		return false;
    std::string title_to_update = trim(tokens[0]);
    std::string genre_to_update = trim(tokens[1]);
	Movie movie(trim(tokens[2]), trim(tokens[3]), std::stoi(tokens[4]), std::stoi(tokens[5]), trim(tokens[6]));
	return repo.updateMovieRepository(movie, title_to_update, genre_to_update);
}

std::vector<Movie> Service::getAllMoviesService()
{
    return repo.getMovies();
}

std::vector<Movie> Service::getMoviesByGenreService(std::string& genre)
{
    return repo.getMoviesByGenreRepository(genre);
}

void Service::watchTrailerService(const std::string& title)
{
    ShellExecuteA(NULL, "open", title.c_str(), NULL, NULL, SW_SHOWNORMAL);
    return;
}

std::vector<WatchList> Service::seeWatchListService()
{
    return repo.seeWatchListRepository();
}

std::vector<WatchList> Service::addMovieToWatchListService(Movie& movie_to_add)
{
    return repo.addMovieToWatchListRepository(movie_to_add);
}

void Service::likeMovieService(WatchList& movie)
{
    repo.likeMovieRepository(movie);
}

void Service::deleteMovieFromWatchListService(WatchList& movie)
{
    repo.deleteMovieFromWatchListRepository(movie);
}

void Service::saveToFileWatchListService(int optionForSave)
{
	repo.saveToFileWatchListRepository(optionForSave);
}

//it undoes the last operation
/*void Service::undo()
{
    repo.undo();
}

void Service::redo()
{
   // repo.redo;
}

void Service::cleanup() {
    // Explicitly call the repository destructor operations
    repo.writeToFile();
    repo.WriteWatchListToFile();
}*/