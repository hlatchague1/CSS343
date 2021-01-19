#pragma once

#include <string>
#include "movie.h"

using namespace std;

class Comedy : public Movie {
 public:
  Comedy(int stockAmount, string directorFirstName,
                string directorLastName, string movieTitle, int releaseYear);
  ~Comedy();

  // sorted by Title, then Year released
  bool operator==(const Movie &otherMovie) const;
  bool operator!=(const Movie &otherMovie) const;
  bool operator<(const Movie &otherMovie) const;
  bool operator>(const Movie &otherMovie) const;
};

// me