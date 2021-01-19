#include "moviestore.h"

// empty constructor creates the
// store's inventory
MovieStore::MovieStore() {
  char mediaType = 'D';
  map<const char, vector<Movie *>> map1;
  storeInventory = {{mediaType, map1}};

  vector<Movie *> vector1, vector2, vector3;
  storeInventory.at(mediaType) = {
      {'C', vector1}, {'D', vector2}, {'F', vector3}};
}

MovieStore::~MovieStore() {}

// returns the store's inventory
map<const char, map<const char, vector<Movie *>>>
MovieStore::GetMovieInventory() {
  return storeInventory;
}

// separates the customer's ID, first and last name
vector<string> MovieStore::SeparateCustomerCommand(string commandLine) {
  vector<string> separatedCCVector;
  string commandPart;

  for (int i = 0; i <= commandLine.size(); i++) {
    if (commandLine[i] == ' ' || i == commandLine.size()) {
      separatedCCVector.push_back(commandPart);
      commandPart = "";
    } else {
      commandPart.push_back(commandLine[i]);
    }
  }

  return separatedCCVector;
}

// reads the data4movies file and passes
// the line to MovieFactory, returns true
// if it successfully reads through the whole file
bool MovieStore::ReadMovies(string fileName) {
  ifstream moviesFile;
  moviesFile.open(fileName);
  string lineInput;
  MovieFactory movieFactory;
  char mediaType = 'D';

  while (moviesFile.is_open()) {
    getline(moviesFile, lineInput);

    if (lineInput == "") {
      break;
    }

    Movie *nMovie = movieFactory.CreateMovie(lineInput);
    if (nMovie == nullptr) {
      continue;
    }
    char movieType = nMovie->GetMovieType();

    for (int i = 0; i < storeInventory.at(mediaType).at(movieType).size();
         i++) {
      if (storeInventory.at(mediaType).at(movieType).at(i) == nMovie) {
        storeInventory.at(mediaType).at(movieType).at(i)->SetStockAmount(
            storeInventory.at(mediaType).at(movieType).at(i)->GetStockAmount() +
            nMovie->GetStockAmount());
        delete nMovie;
        continue;
      }
    }

    storeInventory.at(mediaType).at(movieType).push_back(nMovie);
  }
  return true;
}

// reads the data4customers file and calls
// SeparateCustomerCommand, returns true
// if it successfully reads through the whole file
bool MovieStore::ReadCustomers(string fileName) {
  ifstream customersFile;
  customersFile.open(fileName);
  string lineInput;

  while (customersFile.is_open()) {
    getline(customersFile, lineInput);
    if (lineInput == "") {
      break;
    }
    vector<string> commandsVector = SeparateCustomerCommand(lineInput);
    try {
      stoi(commandsVector[0]);
    } catch (invalid_argument) {
      cout << "ID for line: " << lineInput << "is invalid";
      continue;
    }
    int customerID = stoi(commandsVector[0]);
    if (commandsVector.size() != 3) {
      cout << "Customer information for line: " << lineInput << "is incomplete";
      continue;
    }
    if (customerID < 0 || customerID > 9999) {
      cout << customerID << " is invalid, must be between 0 and 9999!" << endl;
      continue;
    }

    Customer *nCustomer;
    nCustomer = new Customer(customerID, commandsVector[2], commandsVector[1]);
    customerList.Insert(customerID, nCustomer);
  }
  return true;
}

// reads the data4commands file and passes
// each line onto TransactionFactory,
// returns true if it successfully reads
// through the whole file
bool MovieStore::ReadCommands(string fileName) {
  ifstream commandsFile;
  commandsFile.open(fileName);
  string lineInput;
  TransactionFactory transactionFactory;

  while (commandsFile.is_open()) {
    getline(commandsFile, lineInput);
    if (lineInput == "") {
      break;
    }
    Transactions *nTransaction = transactionFactory.CreateTransaction(
        lineInput, customerList, GetMovieInventory());
  }
  return true;
}
