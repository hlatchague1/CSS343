#pragma once

#include <string>

using namespace std;

class Movie {
 protected:
  char movieType = ' ';
  string movieTitle = "";
  int stockAmount = 0;
  string directorFirstName = "";
  string directorLastName = "";
  int releaseYear = 0;
  string movieStatus = "";
  int totalStock = 0;

 public:
  virtual ~Movie() = default;
  char GetMovieType() const;
  string GetMovieTitle() const;
  int GetStockAmount() const;
  string GetDirectorFirstName() const;
  string GetDirectorLastName() const;
  int GetReleaseYear() const;
  string GetMovieStatus() const;
  virtual string GetFeaturedActorFirstName() const;
  virtual string GetFeaturedActorLastName() const;
  virtual int GetReleaseMonth() const;

  void SetMovieTitle(string title);
  void SetStockAmount(int stock);
  void SetDirectorFirstName(string directorFirstName);
  void SetDirectorLastName(string directorLastName);
  void SetReleaseYear(int releaseYear);
  void SetMovieStatus(string status);

  virtual bool operator==(const Movie &otherMovie) const = 0;
  virtual bool operator!=(const Movie &otherMovie) const = 0;
  virtual bool operator<(const Movie &otherMovie) const = 0;
  virtual bool operator>(const Movie &otherMovie) const = 0;
};