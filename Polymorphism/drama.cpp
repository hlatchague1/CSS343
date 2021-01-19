#include "drama.h"

// overloaded constructor, creates new movie
// of type D for drama
Drama::Drama(int stockAmount, string directorFirstName, string directorLastName,
             string movieTitle, int releaseYear) {
  this->stockAmount = stockAmount;
  this->directorFirstName = directorFirstName;
  this->directorLastName = directorLastName;
  this->movieTitle = movieTitle;
  this->releaseYear = releaseYear;
  this->movieType = 'D';
}

Drama::~Drama() = default;

// tests to see if the two drama movies are equal,
// returns true if they are equal
bool Drama::operator==(const Movie &otherMovie) const {
  if ((otherMovie.GetDirectorFirstName() == this->directorFirstName) &&
      (otherMovie.GetDirectorLastName() == this->directorLastName) &&
      (otherMovie.GetMovieTitle() == this->movieTitle) &&
      (otherMovie.GetReleaseYear() == this->releaseYear)) {
    return true;
  }

  return false;
}

// tests to see if the two drama movies are not equal
// returns false if they are not equal
bool Drama::operator!=(const Movie &otherMovie) const {
  if (otherMovie == *this) {
    return false;
  }

  return true;
}

// checks if this movie is less than other movie
// returns true if it is
bool Drama::operator<(const Movie &otherMovie) const {
  if ((this->directorLastName == otherMovie.GetDirectorFirstName()) &&
      (this->directorFirstName == otherMovie.GetDirectorLastName())) {
    if (this->releaseYear < otherMovie.GetReleaseYear()) {
      return true;
    }
    if (this->releaseYear < otherMovie.GetReleaseYear()) {
      return true;
    }
  } else if (this->directorLastName < otherMovie.GetDirectorLastName()) {
    return true;
  }

  return false;
}

// checks if this movie is greater than other movie
// returns true if it is
bool Drama::operator>(const Movie &otherMovie) const {
  if ((this->directorLastName == otherMovie.GetDirectorLastName()) &&
      (this->directorFirstName == otherMovie.GetDirectorFirstName())) {
    if (this->releaseYear > otherMovie.GetReleaseYear()) {
      return true;
    }
    if (this->releaseYear > otherMovie.GetReleaseYear()) {
      return true;
    }
  } else if (this->directorLastName > otherMovie.GetDirectorLastName()) {
    return true;
  }

  return false;
}
