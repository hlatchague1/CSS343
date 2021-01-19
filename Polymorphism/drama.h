#pragma once

#include <string>
#include "movie.h"

using namespace std;

class Drama : public Movie {
 public:
  Drama(int stockAmount, string directorFirstName, string directorLastName,
        string movieTitle, int releaseYear);
  ~Drama();

  //sorted by Director, then Title 
  bool operator==(const Movie &otherMovie) const;
  bool operator!=(const Movie &otherMovie) const;
  bool operator<(const Movie &otherMovie) const;
  bool operator>(const Movie &otherMovie) const;
};