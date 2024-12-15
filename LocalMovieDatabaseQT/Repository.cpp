#include "Repository.h"
#include "Utils.h"
#include "Validator.h"
#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>


Repository::Repository()
{
    this->file_name = "Settings.txt";
    this->file_name_watch_list = "Watch_List.txt";
    this->readFromFile();
    this->ReadWatchListFromFile();
}

Repository::~Repository() 
{
	this->writeToFile();
    this->WriteWatchListToFile();
}

bool Repository::addMovieRepository(Movie& movie_to_add) {
    try {
        MovieValidator::validate(movie_to_add);

        if (std::find_if(movies.begin(), movies.end(), [&movie_to_add](Movie& movie) {
            return movie.getTitle() == movie_to_add.getTitle() && movie.getGenre() == movie_to_add.getGenre();
            }) != movies.end()) {
            throw RepositoryException("Movie already exists.");
        }

        movies.push_back(movie_to_add);
        return true;
    }
    catch (const ValidationException& ex) {
        std::cerr << "Validation error: " << ex.what() << std::endl;
        return false;
    }
    catch (const RepositoryException& ex) {
        std::cerr << "Repository error: " << ex.what() << std::endl;
        return false;
    }
}

bool Repository::deleteMovieRepository(std::string& title) {
    try {
        auto it = std::find_if(movies.begin(), movies.end(), [&title](Movie& movie) {
            return movie.getTitle() == title;
            });

        if (it == movies.end()) {
            throw RepositoryException("Movie not found.");
        }

        movies.erase(it);
        return true;
    }
    catch (const RepositoryException& ex) {
        std::cerr << "Repository error: " << ex.what() << std::endl;
        return false;
    }
}

bool Repository::updateMovieRepository(Movie& movie_to_update, std::string& title_to_update, std::string& genre_to_update) {
    try {
        MovieValidator::validate(movie_to_update);

        auto it = std::find_if(movies.begin(), movies.end(), [&title_to_update, &genre_to_update](Movie& movie) {
            return movie.getTitle() == title_to_update && movie.getGenre() == genre_to_update;
            });

        if (it == movies.end()) {
            throw RepositoryException("Movie not found.");
        }

        *it = movie_to_update; // Update the movie
        return true;
    }
    catch (const ValidationException& ex) {
        std::cerr << "Validation error: " << ex.what() << std::endl;
        return false;
    }
    catch (const RepositoryException& ex) {
        std::cerr << "Repository error: " << ex.what() << std::endl;
        return false;
    }
}
std::vector<Movie> Repository::getMovies()
{
    return movies;
}

std::vector<Movie> Repository::getMoviesByGenreRepository(std::string& genre)
{
    std::vector<Movie> movies_by_genre;
    for (auto& movie : this->movies) 
    {
        if (movie.getGenre() == genre) 
        {
            movies_by_genre.push_back(movie);
        }
    }
    return movies_by_genre;
}

std::vector<WatchList> Repository::seeWatchListRepository()
{
    return watch_list;
}

std::vector<WatchList> Repository::addMovieToWatchListRepository(Movie& movie_to_add)
{
    WatchList watch_list_to_add;
    watch_list_to_add.setTitle(movie_to_add.getTitle());
    watch_list_to_add.setGenre(movie_to_add.getGenre());
    watch_list_to_add.setYear(movie_to_add.getYear());
    watch_list_to_add.setLikes(movie_to_add.getLikes());
    watch_list_to_add.setTrailer(movie_to_add.getTrailer());

    watch_list.push_back(watch_list_to_add);
    return watch_list;
}

void Repository::likeMovieRepository(WatchList& movie)
{
    auto it = std::find_if(watch_list.begin(), watch_list.end(), [&movie](WatchList& wl) 
        {
        return wl.getTitle() == movie.getTitle();
        });

    if (it != watch_list.end()) {
        it->incrementLikes();
        for (auto& mov : movies) {
            if (mov.getTitle() == it->getTitle()) {
                mov.setLikes(it->getLikes());
                break;
            }
        }
    }
}

void Repository::deleteMovieFromWatchListRepository(WatchList& movie)
{
    auto it = std::find_if(watch_list.begin(), watch_list.end(), [&movie](WatchList& wl) {
        return wl.getTitle() == movie.getTitle();
        });

    if (it != watch_list.end()) {
        watch_list.erase(it);
    }
}

void Repository::ReadWatchListFromFile()
{
	std::string line_read_from_file;
	std::ifstream file(file_name_watch_list);
    if (file.is_open())
    {
        while (std::getline(file, line_read_from_file))
        {
			line_read_from_file = trim(line_read_from_file);
			std::vector<std::string> tokens = tokenize(line_read_from_file, ',');
			if (tokens.size() != 5)
				continue;
			WatchList watch_list(trim(tokens[0]), trim(tokens[1]), std::stoi(tokens[2]), std::stoi(tokens[3]), trim(tokens[4]));
			this->watch_list.push_back(watch_list);
		}
		file.close();
	}
}

void Repository::WriteWatchListToFile()
{
	std::ofstream file(file_name_watch_list, std::ofstream::out);
	WatchList watch_list;
    if (file.is_open()) {
        for (auto& watch_list : this->watch_list) {
			file << watch_list.getTitle() << ", " << watch_list.getGenre() << ", " << watch_list.getYear() << ", " << watch_list.getLikes() << "," << watch_list.getTrailer() << '\n';
		}
	}
	file.close();
}

void Repository::readFromFile() 
{
    std::string line_read_from_file;
    std::ifstream file(file_name);
    if (file.is_open())
    {
        while (std::getline(file, line_read_from_file))
        {
            line_read_from_file = trim(line_read_from_file);
			std::vector<std::string> tokens = tokenize(line_read_from_file, ',');
			if (tokens.size() != 5)
				continue;
			Movie movie(trim(tokens[0]), trim(tokens[1]), std::stoi(tokens[2]), std::stoi(tokens[3]), trim(tokens[4]));
			this->movies.push_back(movie);
		}
        file.close();
    }
}

void Repository::writeToFile() 
{
    std::ofstream file(file_name, std::ofstream::out);
    Movie movie;
    if (file.is_open()) {
        for (auto& movie : this->movies) 
        {
            file << movie.getTitle() << ", " << movie.getGenre() << ", " << movie.getYear() << ", " << movie.getLikes() << "," << movie.getTrailer() << '\n';
        }
    }
    file.close();
}


void Repository::saveToFileWatchListRepository(int optionForSave)
{

    //this option should save the WatchList in an excell file
    if (optionForSave == 2)
	{
        file_name_watch_list = "Watch_List.csv";
        std::ofstream file(file_name_watch_list, std::ofstream::out);
        WatchList watch_list;
        if (file.is_open()) {
			for (auto& watch_list : this->watch_list) {
				file << watch_list.getTitle() << ", " << watch_list.getGenre() << ", " << watch_list.getYear() << ", " << watch_list.getLikes() << "," << watch_list.getTrailer() << '\n';
			}
		}
        file.close();
	}
	else if (optionForSave == 1)
	{
		file_name_watch_list = "Watch_List.html";
		std::ofstream file(file_name_watch_list, std::ofstream::out);
		WatchList watch_list;
		if (file.is_open()) {
			file << "<!DOCTYPE html>\n";
			file << "<html>\n";
			file << "<head>\n";
			file << "<title>Watch List</title>\n";
			file << "</head>\n";
			file << "<body>\n";
			file << "<table border=\"1\">\n";
			file << "<tr>\n";
			file << "<td>Title</td>\n";
			file << "<td>Genre</td>\n";
			file << "<td>Year</td>\n";
			file << "<td>Likes</td>\n";
			file << "<td>Trailer</td>\n";
			file << "</tr>\n";
			for (auto& watch_list : this->watch_list) {
				file << "<tr>\n";
				file << "<td>" << watch_list.getTitle() << "</td>\n";
				file << "<td>" << watch_list.getGenre() << "</td>\n";
				file << "<td>" << watch_list.getYear() << "</td>\n";
				file << "<td>" << watch_list.getLikes() << "</td>\n";
				file << "<td>" << watch_list.getTrailer() << "</td>\n";
				file << "</tr>\n";
			}
			file << "</table>\n";
			file << "</body>\n";
			file << "</html>\n";
		}
		file.close();
	}

    //open the file in their respective programs (excel, browser)
    std::string command = "start " + file_name_watch_list;
    system(command.c_str());
}

/*void Repository::undo()
{
    if (undoActions.empty())
    {
		throw RepositoryException("No more undos!");
	}
	auto action = undoActions.back();
	undoActions.pop_back();
	action->executeUndo();
	redoActions.push_back(std::move(action));
}

void Repository::redo()
{
    if (redoActions.empty())
    {
		throw RepositoryException("No more redos!");
	}
	auto action = redoActions.back();
	redoActions.pop_back();
	action->executeRedo();
	undoActions.push_back(std::move(action));
}*/