#include <iostream>
#include <sstream>
#include <vector>
#include "classic.h"
#include "comedy.h"
#include "drama.h"
#include "movie.h"

class MovieFactory {
 public:
  static Movie* CreateMovie(const string& commandLine);
  virtual ~MovieFactory() = default;

  static vector<string> SplitCommandLine(const string& commandLine);
  static Classic* CreateClassicMovie(vector<string> commandLineVector,
                                     string commandLine);
  static Comedy* CreateComedyMovie(vector<string> commandLineVector,
                                   string commandLine);
  static Drama* CreateDramaMovie(vector<string> commandLineVector,
                                 string commandLine);
};
