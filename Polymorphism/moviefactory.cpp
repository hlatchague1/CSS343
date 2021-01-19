#include "moviefactory.h"

using namespace std;

/*Coordinates functions to return the correct movie type*/
Movie* MovieFactory::CreateMovie(const string& commandLine) {
  vector<string> commandLineVector = SplitCommandLine(commandLine);

  switch (commandLineVector.size()) {
    case 0:
      return nullptr;
    case 6:
      if (commandLineVector[0] == "D") {
        return CreateDramaMovie(commandLineVector, commandLine);
      }
      if (commandLineVector[0] == "F") {
        return CreateComedyMovie(commandLineVector, commandLine);
      }
      cout << "Genre " << commandLineVector[0]
           << " not found in line: " << commandLine << endl;
      return nullptr;
    case 9:
      if (commandLineVector[0] == "C") {
        return CreateClassicMovie(commandLineVector, commandLine);
      }
      cout << "Genre " << commandLineVector[0]
           << " not found in line: " << commandLine << endl;
      return nullptr;
    default:
      cout << "Something is wrong with line: " << commandLine << endl;
      return nullptr;
  }
  return nullptr;
}

/*Separates each line sent through the ReadMovies into an
  array that is returned*/
vector<string> MovieFactory::SplitCommandLine(const string& commandLine) {
  vector<string> commandLineVector;
  int commandLineSize = commandLine.size();
  int commasSeen = 0;
  int spacesSeen = 0;
  string commandGroup = "";

  for (int i = 0; i <= commandLineSize; i++) {
    for (i; commasSeen != 4 && i < commandLineSize; i++) {
      if (commandLine[i] == ',') {
        commasSeen++;
        spacesSeen++;
        if (i + 1 <= commandLineSize) {
          i++;
        } else {
          cout << "Incorrect formatting for line: " << commandLine << endl;
          commandLineVector.resize(0);
          return commandLineVector;
        }
        commandLineVector.push_back(commandGroup);
        commandGroup = "";
        continue;
      }
      if (commandLine[i] == ' ' && spacesSeen == 3 && commasSeen != 3) {
        commandGroup += commandLine[i];
        continue;
      }
      if (commandLine[i] == ' ' && commasSeen != 3) {
        spacesSeen++;
        commandLineVector.push_back(commandGroup);
        commandGroup = "";
        continue;
      }
      commandGroup += commandLine[i];
    }
    if (commandLine[i] == ' ' || i == commandLineSize) {
      spacesSeen++;
      commandLineVector.push_back(commandGroup);
      commandGroup = "";
      continue;
    }
    commandGroup += commandLine[i];
  }
  return commandLineVector;
}

/*Creates and returns a Classic Movie obj*/
Classic* MovieFactory::CreateClassicMovie(vector<string> commandLineVector,
                                          string commandLine) {
  char movieType;
  int stockAmount;
  string directorFirstName;
  string directorLastName;
  string movieTitle;
  string actorFirstName;
  string actorLastName;
  int releaseMonth;
  int releaseYear;

  try {
    movieType = commandLineVector[0][0];
    stockAmount = stoi(commandLineVector[1]);
    directorFirstName = commandLineVector[2];
    directorLastName = commandLineVector[3];
    movieTitle = commandLineVector[4];
    actorFirstName = commandLineVector[5];
    actorLastName = commandLineVector[6];
    releaseMonth = stoi(commandLineVector[7]);
    releaseYear = stoi(commandLineVector[8]);
  } catch (invalid_argument) {
    cout << "Invalid command: " << commandLine << endl;
    return nullptr;
  }
  return new Classic(stockAmount, directorFirstName, directorLastName,
                     movieTitle, actorFirstName, actorLastName, releaseMonth,
                     releaseYear);
}

/*Creates and returns a Comedy Movie obj*/
Comedy* MovieFactory::CreateComedyMovie(vector<string> commandLineVector,
                                        string commandLine) {
  char movieType;
  int stockAmount;
  string directorFirstName;
  string directorLastName;
  string movieTitle;
  int releaseYear;

  try {
    movieType = commandLineVector[0][0];
    stockAmount = stoi(commandLineVector[1]);
    directorFirstName = commandLineVector[2];
    directorLastName = commandLineVector[3];
    movieTitle = commandLineVector[4];
    releaseYear = stoi(commandLineVector[5]);
  } catch (invalid_argument) {
    cout << "Invalid command: " << commandLine << endl;
    return nullptr;
  }

  return new Comedy(stockAmount, directorFirstName, directorLastName,
                    movieTitle, releaseYear);
}

/*Creates and returns a Drama Movie obj*/
Drama* MovieFactory::CreateDramaMovie(vector<string> commandLineVector,
                                      string commandLine) {
  char movieType;
  int stockAmount;
  string directorFirstName;
  string directorLastName;
  string movieTitle;
  int releaseYear;

  try {
    movieType = commandLineVector[0][0];
    stockAmount = stoi(commandLineVector[1]);
    directorFirstName = commandLineVector[2];
    directorLastName = commandLineVector[3];
    movieTitle = commandLineVector[4];
    releaseYear = stoi(commandLineVector[5]);
  } catch (invalid_argument) {
    cout << "Invalid command: " << commandLine << endl;
    return nullptr;
  }

  return new Drama(stockAmount, directorFirstName, directorLastName, movieTitle,
                   releaseYear);
}
