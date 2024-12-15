/*#include "UserInterface.h"
#include <string>
#include <iostream>

UserInterface::UserInterface() 
{
	this->optionForSave = 0;
}

UserInterface :: ~UserInterface()
{
}

//Adds a movie to the repository
void UserInterface::addMovie()
{
	std::string genre_input;
	std::string title_input;
	int year_input;
	int likes_input;
	std::string trailer_input;

	std::cout << "Enter the title: ";
	std::cin >> title_input;
	std::cout << "Enter the genre: ";
	std::cin >> genre_input;
	std::cout << "Enter the year: ";
	std::cin >> year_input;
	std::cout << "Enter the likes: ";
	std::cin >> likes_input;
	std::cout << "Enter the trailer: ";
	std::cin >> trailer_input;

	Movie movie = Movie(title_input, genre_input, year_input, likes_input, trailer_input);

	if (this->service.addMovieService(movie) == false)
	{
		std::cout << "The movie already exists!" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "The movie was added!" << std::endl;
		std::cout << std::endl;
	}
}

//Deletes a movie from the repository
void UserInterface::deleteMovie()
{
	std::string title_input;
	std::cout << "Enter the title: ";
	std::cin.ignore();
	std::getline(std::cin, title_input);

	if (this->service.deleteMovieService(title_input) == false)
	{
		std::cout << "The movie does not exist!" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "The movie was deleted!" << std::endl;
		std::cout << std::endl;
	}
}

//Updates a movie from the repository
void UserInterface::updateMovie()
{
	std::string genre_input;
	std::string title_input;
	std::string title_to_update;
	std::string genre_to_update;

	int year_input;
	int likes_input;
	std::string trailer_input;

	std::cout << "Enter the title of the movie you want to update: ";
	std::cin.ignore();
	std::getline(std::cin, title_to_update);
	std::cout << "Enter the genre of the movie you want to update: ";
	std::cin.ignore();
	std::cin >> genre_to_update;
	std::cout << "Enter the title: ";
	std::cin >> title_input;
	std::cout << "Enter the genre: ";
	std::cin >> genre_input;
	std::cout << "Enter the year: ";
	std::cin >> year_input;
	std::cout << "Enter the likes: ";
	std::cin >> likes_input;
	std::cout << "Enter the trailer: ";
	std::cin >> trailer_input;
	std::cout << std::endl;

	Movie movie = Movie(title_input, genre_input, year_input, likes_input, trailer_input);

	if (this->service.updateMovieService(movie, title_to_update, genre_to_update) == false)
	{
		std::cout << "The movie does not exist!" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "The movie was updated!" << std::endl;
		std::cout << std::endl;
	}
}

//Displays all the movies from the repository
void UserInterface::displayMovies() {
	std::vector<Movie> movies = service.getAllMoviesService();

	for (auto& m : movies) {
		std::cout << m.getTitle() << " " << m.getGenre() << " " << m.getYear() << " " << m.getLikes() << " " << m.getTrailer() << std::endl;
	}
	std::cout << std::endl;
}

//Displays all the movies from the repository by genre
void UserInterface::displayMoviesByGenre() {
	std::string genre_input;
	std::cout << "Enter the genre: ";
	std::cin.ignore();
	std::getline(std::cin, genre_input);

	std::vector<Movie> movies;
	if (genre_input.empty()) {
		displayMovies();
		movies = service.getAllMoviesService();
	}
	else {
		movies = service.getMoviesByGenreService(genre_input);
	}

	for (int i = 0; i < movies.size(); i++) {
		auto& m = movies[i];
		std::cout << m.getTitle() << " " << m.getGenre() << " " << m.getYear() << " " << m.getLikes() << " " << m.getTrailer() << std::endl;

		service.watchTrailerService(m.getTitle());
		std::cout << "Do you want to add this movie to your watch list?" << std::endl;
		std::cout << "1. Yes" << std::endl;
		std::cout << "2. No" << std::endl;
		std::cout << "3. Next movie" << std::endl;
		std::cout << "4. Exit" << std::endl;
		std::cout << std::endl;

		int option;
		std::cin >> option;
		if (option == 1) {
			service.addMovieToWatchListService(m);
		}
		else if (option == 4) {
			break;
		}
		else if (option == 3) {
			i++;
		}

		if (i + 1 == movies.size()) {
			i = -1; // Resetting to 0 for the next iteration
		}
	}
}


//Displays the watch list
void UserInterface::seeWatchList() {
	while (true)
	{
		std::vector<WatchList> watch_list = service.seeWatchListService();

		if (watch_list.empty()) {
			std::cout << "The watch list is empty!" << std::endl << std::endl;
			break;
		}

		int option;

		for (int i = 0; i < watch_list.size(); i++) {
			auto& wl = watch_list[i];
			std::cout << wl.getTitle() << " " << wl.getGenre() << " " << wl.getYear() << " " << wl.getLikes() << " " << wl.getTrailer() << std::endl;
			std::cout << "1. Like" << std::endl;
			std::cout << "2. Delete" << std::endl;
			std::cout << "3. Next" << std::endl;
			std::cout << "4. Exit" << std::endl;
			std::cout << std::endl;

			std::cin >> option;

			if (option == 1) {
				service.likeMovieService(wl);
			}
			else if (option == 2) {
				service.deleteMovieFromWatchListService(wl);
			}
			else if (option == 4) {
				break;
			}
			else if (option == 3) {
				continue;
			}
			if (i + 1 == watch_list.size()) {
				i = -1; // Resetting to 0 for the next iteration
			}
		}

		if (option == 4)
		{
			break;
		}
	}
}

//Displays the menu for saving the watch list
void saveCSVorHTMLMenu()
{
	std::cout << "1. Save to CSV" << std::endl;
	std::cout << "2. Save to HTML" << std::endl;
	std::cout << "3. Exit" << std::endl;
	std::cout << std::endl;
}


//Displays the choice between admin and user
void choiceAdminUser()
{
	std::cout << "1. Admin" << std::endl;
	std::cout << "2. User" << std::endl;
	std::cout << "3. Exit" << std::endl;
	std::cout << std::endl;
}

//Displays the menu for the admin
void printMenuAdmin()
{
	std::cout << "1. Add movie" << std::endl;
	std::cout << "2. Delete movie" << std::endl;
	std::cout << "3. Update movie" << std::endl;
	std::cout << "4. See all movies" << std::endl;
	std::cout << "5. Exit" << std::endl;
	std::cout << std::endl;

}

//Displays the menu for the user
void printMenuUser()
{
	std::cout << "1. Dysplay Movies by genre" << std::endl;
	std::cout << "2. See watch list" << std::endl;
	std::cout << "3. Dysplay all movies" << std::endl;
	std::cout << "4. Save to file WatchList" << std::endl;
	std::cout << "5. Exit" << std::endl;
	std::cout << std::endl;

}

//Displays the menu for the user in advanced mode
void printMenuUserAdvanced()
{
	std::cout << "1. Add movie to watch list" << std::endl;
	std::cout << "2. Delete movie from watch list" << std::endl;
	std::cout << "3. Next" << std::endl;
	std::cout << std::endl;

}

//Runs the application
void UserInterface::run()
{
	int option;

	saveCSVorHTMLMenu();
	std::cin >> option;

	this->optionForSave = option;


	while (true)
	{
		choiceAdminUser();
		std::cin >> option;

		if (option == 1)
		{
			this->runAdmin();
		}
		else if (option == 2)
		{
			this->runUser();
		}
		else
		{
			break;
		}
	}
}

//Runs the application in admin mode
void UserInterface::runAdmin()
{
	int option;

	while (true)
	{
		printMenuAdmin();
		std::cin >> option;

		switch (option)
		{
		case 1:
			this->addMovie();
			break;
		case 2:
			this->deleteMovie();
			break;
		case 3:
			this->updateMovie();
			break;
		case 4:
			this->displayMovies();
			break;
		case 5:
			break;
		}

		if (option == 5)
		{
			break;
		}

	}
}

//Runs the application in user mode
void UserInterface::runUser()
{
	int option;

	while (true)
	{
		printMenuUser();
		std::cin >> option;

		switch (option)
		{
		case 1:
			this->displayMoviesByGenre();
			break;
		case 2:
			this->seeWatchList();
			break;
		case 3:
			this->displayMovies();
			break;
		case 4:
			this->service.saveToFileWatchListService(this->optionForSave);
			break;
		case 5:
			break;
		}

		if (option == 4)
		{
			break;
		}

	}
}
*/