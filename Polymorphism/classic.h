#pragma once

#include <string>
#include <vector>
#include "movie.h"

using namespace std;

class Classic : public Movie {
 private:
  string featuredActorFirstName = "";
  string featuredActorLastName = "";
  int releaseMonth = 0;

 public:
  Classic(int stockAmount, string directorFirstName, string directorLastName,
          string movieTitle, string actorFirstName, string actorLastName,
          int releaseMonth, int releaseYear);
  ~Classic();

  string GetFeaturedActorFirstName() const;
  string GetFeaturedActorLastName() const;
  int GetReleaseMonth() const;

  // sorted by Release date, then Major actor
  bool operator==(const Movie &otherMovie) const;
  bool operator!=(const Movie &otherMovie) const;
  bool operator<(const Movie &otherMovie) const;
  bool operator>(const Movie &otherMovie) const;
};