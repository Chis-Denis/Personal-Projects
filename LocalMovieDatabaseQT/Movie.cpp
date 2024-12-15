#include "Movie.h"
#include "Utils.h"
#include <string>
#include <vector>
#include <iostream>

// Operator >> overloading for reading a movie object from the input stream
std::istream& operator>>(std::istream& inputFile, Movie& movieToRead) {
    std::string lineRead;
    std::getline(inputFile, lineRead);
    std::vector<std::string> tokens = tokenize(lineRead, ',');
    if (tokens.size() != 5)
        return inputFile;
    movieToRead.setTitle(tokens[0]);
    movieToRead.setGenre(tokens[1]);
    movieToRead.setYear(std::stoi(tokens[2]));
    movieToRead.setLikes(std::stoi(tokens[3]));
    movieToRead.setTrailer(tokens[4]);
    return inputFile;
}

// Operator << overloading for writing a movie object to the output stream
std::ostream& operator<<(std::ostream& outputFile, const Movie& movieToWrite) {
    outputFile << movieToWrite.getTitle() << "," << movieToWrite.getGenre() << "," << movieToWrite.getYear() << "," << movieToWrite.getLikes() << "," << movieToWrite.getTrailer() << "\n";
    return outputFile;
}
