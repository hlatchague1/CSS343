#include "comedy.h"

// overloaded constructor, creates new movie
// of type F for funny
Comedy::Comedy(int stockAmount, string directorFirstName, string directorLastName, string movieTitle,
              int releaseYear) {
  this->movieType = 'F';
  this->movieTitle = movieTitle;
  this->stockAmount = stockAmount;
  directorFirstName = directorFirstName;
  directorLastName = directorLastName;
  this->releaseYear = releaseYear;
  this->movieType = 'F';
}

Comedy::~Comedy() = default;

// tests to see if the two comedy movies are equal,
// returns true if they are equal
bool Comedy::operator==(const Movie& otherMovie) const {
  if (movieTitle == otherMovie.GetMovieTitle()) {
    if (releaseYear == otherMovie.GetReleaseYear()) return true;
  }
  return false;
}

// tests to see if the two comedy movies are not equal
// returns false if they are not equal
bool Comedy::operator!=(const Movie& otherMovie) const {
  if (movieTitle == otherMovie.GetMovieTitle()) {
    if (releaseYear == otherMovie.GetReleaseYear()) return false;
  }
  return true;
}

// checks if this movie is less than other movie
// returns true if it is
bool Comedy::operator<(const Movie& otherMovie) const { 
	if (movieTitle < otherMovie.GetMovieTitle()) {
    if (releaseYear < otherMovie.GetReleaseYear()) return true;
  }
  return false;
}

// checks if this movie is greater than other movie
// returns true if it is
bool Comedy::operator>(const Movie& otherMovie) const {
  if (movieTitle > otherMovie.GetMovieTitle()) {
    if (releaseYear > otherMovie.GetReleaseYear()) return true;
  }
  return false;
}

