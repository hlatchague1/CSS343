#include "classic.h"

// overloaded constructor, creates new movie
// of type C for classic
Classic::Classic(int stockAmount, string directorFirstName,
                 string directorLastName, string movieTitle,
                 string actorFirstName, string actorLastName, int releaseMonth,
                 int releaseYear) {
  this->stockAmount = stockAmount;
  this->directorFirstName = directorFirstName;
  this->directorLastName = directorLastName;
  this->movieTitle = movieTitle;
  this->releaseMonth = releaseMonth;
  this->featuredActorFirstName = actorFirstName;
  this->featuredActorLastName = actorLastName;
  this->releaseYear = releaseYear;
  this->releaseMonth = releaseMonth;
  this->movieType = 'C';
}

Classic::~Classic() = default;

// returns the featured actor's first name
string Classic::GetFeaturedActorFirstName() const {
  return featuredActorFirstName;
}

// returns the featured actor's last name
string Classic::GetFeaturedActorLastName() const {
  return featuredActorLastName;
}

// returns the movie's release month
int Classic::GetReleaseMonth() const { return releaseMonth; }

// tests to see if the two classic movies are equal,
// returns true if they are equal
bool Classic::operator==(const Movie& otherMovie) const {
  if ((otherMovie.GetDirectorFirstName() == this->directorFirstName) &&
      (otherMovie.GetDirectorLastName() == this->directorLastName) &&
      (otherMovie.GetMovieTitle() == this->movieTitle) &&
      (otherMovie.GetReleaseYear() == this->releaseYear)) {
    return true;
  }
  return false;
}

// tests to see if the two classic movies are not equal
// returns false if they are not equal
bool Classic::operator!=(const Movie& otherMovie) const {
  if (otherMovie == *this) {
    return false;
  }
  return true;
}

// checks if this movie is less than other movie
// returns true if it is
bool Classic::operator<(const Movie& otherMovie) const {
  if ((this->releaseYear == otherMovie.GetReleaseYear())) {
    if (featuredActorLastName < otherMovie.GetFeaturedActorLastName()) {
      if (featuredActorFirstName < otherMovie.GetFeaturedActorFirstName()) {
        return true;
      }
      return false;
    }
    return false;
  }
  if (this->releaseYear < otherMovie.GetReleaseYear()) {
    return true;
  }
  return false;
}

// checks if this movie is greater than other movie
// returns true if it is
bool Classic::operator>(const Movie& otherMovie) const {
  if (this->releaseYear == otherMovie.GetReleaseYear()) {
    if (featuredActorLastName < otherMovie.GetFeaturedActorLastName()) {
      if (featuredActorFirstName < otherMovie.GetFeaturedActorFirstName()) {
        return true;
      }
    }
  } else if (this->releaseYear > otherMovie.GetReleaseYear()) {
    return true;
  }
  return false;
}
