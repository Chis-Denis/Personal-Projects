#pragma once

#pragma once
#include "Movie.h"
#include "Exceptions.h"

class MovieValidator {
public:
    static void validate(const Movie& movie) {
        if (movie.getTitle().empty()) {
            throw ValidationException("Title cannot be empty.");
        }
        if (movie.getGenre().empty()) {
            throw ValidationException("Genre cannot be empty.");
        }
        if (movie.getYear() < 1888 || movie.getYear() > 2100) {
            throw ValidationException("Year is out of valid range.");
        }
        if (movie.getLikes() < 0) {
            throw ValidationException("Likes cannot be negative.");
        }
        if (movie.getTrailer().empty()) {
            throw ValidationException("Trailer cannot be empty.");
        }
    }
};
