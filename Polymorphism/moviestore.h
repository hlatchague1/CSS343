#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "classic.h"
#include "comedy.h"
#include "drama.h"
#include "moviefactory.h"
#include "transactionfactory.h"

using namespace std;

class MovieStore {
 public:
  MovieStore();
  ~MovieStore();

  /*(mediaType, (movieType, vectorOfMovies))*/
  map<const char, map<const char, vector<Movie*>>> storeInventory;
  HashTable customerList;
  map<const char, map<const char, vector<Movie *>>> GetMovieInventory();
  vector<string> SeparateCustomerCommand(string commandLine);

  bool ReadMovies(string fileName);
  bool ReadCustomers(string fileName);
  bool ReadCommands(string fileName);
};
