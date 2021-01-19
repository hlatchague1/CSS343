#include "movie.h"

// returns the movie's movie type
char Movie::GetMovieType() const { return movieType; }

// returns the movie's title
string Movie::GetMovieTitle() const { return movieTitle; }

// returns the movie's stock amount
int Movie::GetStockAmount() const { return stockAmount; }

// returns the movie's director's first name
string Movie::GetDirectorFirstName() const { return directorFirstName; }

// returns the movie's director's last name
string Movie::GetDirectorLastName() const { return directorLastName; }

// returns the movie's release year
int Movie::GetReleaseYear() const { return releaseYear; }

// returns the movie's status
string Movie::GetMovieStatus() const { return movieStatus; }

// sets the movie's title
void Movie::SetMovieTitle(string title) { movieTitle = title; }

// sets the movie's stock amount
void Movie::SetStockAmount(int stock) { stockAmount = stock; }

// sets the movie's director's first name
void Movie::SetDirectorFirstName(string directorFirstName) {
  directorFirstName = directorFirstName;
}

// sets the movie's director's last name
void Movie::SetDirectorLastName(string directorLastName) {
  directorLastName = directorLastName;
}

// sets the movie's release year
void Movie::SetReleaseYear(int releaseYear) { this->releaseYear = releaseYear; }

// sets the movie's status
void Movie::SetMovieStatus(string status) { movieStatus = status; }

// function overrided in Classic class
// gets the movie's featured actor's first name
string Movie::GetFeaturedActorFirstName() const { return ""; }

// function overrided in Classic class
// gets the movie's featured actor's last name
string Movie::GetFeaturedActorLastName() const { return ""; }

// function overrided in Classic class
// gets the movie's release month
int Movie::GetReleaseMonth() const { return -1; }