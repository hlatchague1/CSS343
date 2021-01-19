#include "transactionfactory.h"

// separates each line send through the ReadCommands
// function into the respective variables, and creates
// the correct transaction based off of the transaction type
// which is returned
Transactions* TransactionFactory::CreateTransaction(
    const string& commandLine, HashTable customerList,
    map<const char, map<const char, vector<Movie*>>> movieInventory) {
  vector<string> lineOfCommand;
  stringstream ss(commandLine);
  string intermediate;
  while (getline(ss, intermediate, ' ')) {
    lineOfCommand.push_back(intermediate);
  }
  char transactionType = commandLine[0];
  int customerID = -1;
  if (lineOfCommand.size() > 1) {
    customerID = stoi(lineOfCommand[1]);
  }

  if (transactionType != 'B' && transactionType != 'R' &&
      transactionType != 'H' && transactionType != 'I') {
    cout << transactionType << " is not a valid transaction type." << endl;
    return nullptr;
  }

  if (transactionType == 'H') {
    Customer* customerPtr = customerList.Search(customerID);
    History* nHistory = new History(customerPtr);
    nHistory->Print(customerPtr->GetHistory());
    return nHistory;
  }

  if (transactionType == 'I') {
    Inventory* nInventory = new Inventory();
    nInventory->Print(movieInventory);
    return nInventory;
  }

  string medType = lineOfCommand[2];
  string mType = lineOfCommand[3];
  char mediaType = medType[0];
  char movieType = mType[0];

  if (mediaType != 'D') {
    return nullptr;
  }

  if (movieType != 'C' && movieType != 'F' && movieType != 'D') {
    cout << movieType << " is not a valid movie type." << endl;
    return nullptr;
  }

  string temp;
  for (int i = 4; i < lineOfCommand.size(); ++i) {
    temp += lineOfCommand[i];
    temp += " ";
  }
  if (movieType == 'F') {
    vector<string> secondLineOfCommand;
    stringstream ss2(temp);
    string intermediate2;

    while (getline(ss2, intermediate2, ',')) {
      secondLineOfCommand.push_back(intermediate2);
    }
    string movieTitle = secondLineOfCommand[0];
    int releaseYear = stoi(secondLineOfCommand[1]);

    if (transactionType == 'R') {
      int location = 0;

      for (int i = 0; i < movieInventory.at(mediaType).at(movieType).size();
           i++) {
        if ((movieInventory.at(mediaType)
                 .at(movieType)
                 .at(i)
                 ->GetMovieTitle() == movieTitle) &&
            (movieInventory.at(mediaType)
                 .at(movieType)
                 .at(i)
                 ->GetReleaseYear() == releaseYear)) {
          movieInventory.at(mediaType).at(movieType).at(i)->SetStockAmount(
              movieInventory.at(mediaType)
                  .at(movieType)
                  .at(i)
                  ->GetStockAmount() +
              1);

          location = i;
          break;
        } else {
          location = -1;
        }
      }

      if (location == -1) {
        cout << movieTitle << " was not found in store's inventory." << endl;
      } else {

        if (customerList.Search(customerID) == nullptr) {
          cout << "Customer ID: " << customerID << " not found" << endl;
          return nullptr;
        }

        Returns* nReturns = new Returns(
            customerList.Search(customerID),
            movieInventory.at(mediaType).at(movieType).at(location));
        customerList.Search(customerID)->AddToHistory(nReturns);

        return nReturns;
      }
    }
    if (transactionType == 'B') {
      int location = 0;

      for (int i = 0; i < movieInventory.at(mediaType).at(movieType).size();
           i++) {

        if ((movieInventory.at(mediaType)
                 .at(movieType)
                 .at(i)
                 ->GetMovieTitle() == movieTitle) &&
            (movieInventory.at(mediaType)
                 .at(movieType)
                 .at(i)
                 ->GetReleaseYear() == releaseYear)) {
          int stockAmount = movieInventory.at(mediaType)
                                .at(movieType)
                                .at(i)
                                ->GetStockAmount();
          if (stockAmount == 0) {
            cout << "Movie stock is " << stockAmount << "." << endl;
            return nullptr;
          }

          movieInventory.at(mediaType).at(movieType).at(i)->SetStockAmount(
              movieInventory.at(mediaType)
                  .at(movieType)
                  .at(i)
                  ->GetStockAmount() -
              1);

          location = i;
          break;
        } else {
          location = -1;
        }
      }

      if (location == -1) {
        cout << movieTitle << " was not found in store's inventory." << endl;
      } else {

        if (customerList.Search(customerID) == nullptr) {
          cout << "Customer ID: " << customerID << " not found" << endl;
          return nullptr;
        }

        Borrows* nBorrows = new Borrows(
            customerList.Search(customerID),
            movieInventory.at(mediaType).at(movieType).at(location));
        customerList.Search(customerID)->AddToHistory(nBorrows);
        return nBorrows;
      }
    } else {
      cout << transactionType << " is not a valid transaction type." << endl;
    }

  } else if (movieType == 'D') {
    vector<string> secondLineOfCommand;
    stringstream ss2(temp);
    string intermediate2;
    while (getline(ss2, intermediate2, ',')) {
      secondLineOfCommand.push_back(intermediate2);
    }
    string directorName = secondLineOfCommand[0];
    string directorFirstName;
    string directorLastName;
    vector<string> splitName;
    istringstream iss(directorName);
    do {
      string subs;
      iss >> subs;
      splitName.push_back(subs);
    } while (iss);
    directorFirstName = splitName[0];
    directorLastName = splitName[1];
    string temp = secondLineOfCommand[1];
    if (temp[0] == ' ') temp.erase(0, 1);
    string movieTitle = temp;
    if (transactionType == 'R') {
      int location = 0;

      for (int i = 0; i < movieInventory.at(mediaType).at(movieType).size();
           i++) {
        if ((movieInventory.at(mediaType)
                 .at(movieType)
                 .at(i)
                 ->GetMovieTitle() == movieTitle) &&
            (movieInventory.at(mediaType)
                 .at(movieType)
                 .at(i)
                 ->GetDirectorFirstName() == directorFirstName) &&
            (movieInventory.at(mediaType)
                 .at(movieType)
                 .at(i)
                 ->GetDirectorLastName() == directorLastName)) {
          movieInventory.at(mediaType).at(movieType).at(i)->SetStockAmount(
              movieInventory.at(mediaType)
                  .at(movieType)
                  .at(i)
                  ->GetStockAmount() +
              1);

          location = i;
          break;
        } else {
          location = -1;
        }
      }

      if (location == -1) {
        cout << movieTitle << " was not found in store's inventory." << endl;
      } else {

        if (customerList.Search(customerID) == nullptr) {
          cout << "Customer ID: " << customerID << " not found" << endl;
          return nullptr;
        }

        Returns* nReturns = new Returns(
            customerList.Search(customerID),
            movieInventory.at(mediaType).at(movieType).at(location));
        customerList.Search(customerID)->AddToHistory(nReturns);
        return nReturns;
      }
    }

    if (transactionType == 'B') {
      int location = 0;

      for (int i = 0; i < movieInventory.at(mediaType).at(movieType).size();
           i++) {
        string stupidMovie =
            movieInventory.at(mediaType).at(movieType).at(i)->GetMovieTitle();
        string dumbDirector = movieInventory.at(mediaType)
                                  .at(movieType)
                                  .at(i)
                                  ->GetDirectorFirstName();
        string lastName = movieInventory.at(mediaType)
                              .at(movieType)
                              .at(i)
                              ->GetDirectorLastName();

        if ((movieInventory.at(mediaType)
                 .at(movieType)
                 .at(i)
                 ->GetMovieTitle() == movieTitle) &&
            (movieInventory.at(mediaType)
                 .at(movieType)
                 .at(i)
                 ->GetDirectorFirstName() == directorFirstName) &&
            (movieInventory.at(mediaType)
                 .at(movieType)
                 .at(i)
                 ->GetDirectorLastName() == directorLastName)) {
          int stockAmount = movieInventory.at(mediaType)
                                .at(movieType)
                                .at(i)
                                ->GetStockAmount();
          if (stockAmount == 0) {
            cout << "Movie stock is " << stockAmount << "." << endl;
            return nullptr;
          }

          movieInventory.at(mediaType).at(movieType).at(i)->SetStockAmount(
              movieInventory.at(mediaType)
                  .at(movieType)
                  .at(i)
                  ->GetStockAmount() -
              1);

          location = i;
          break;
        } else {
          location = -1;
        }
      }

      if (location == -1) {
        cout << movieTitle << " was not found in store's inventory." << endl;
      } else {

        if (customerList.Search(customerID) == nullptr) {
          cout << "Customer ID: " << customerID << " not found" << endl;
          return nullptr;
        }

        Borrows* nBorrows = new Borrows(
            customerList.Search(customerID),
            movieInventory.at(mediaType).at(movieType).at(location));
        customerList.Search(customerID)->AddToHistory(nBorrows);
        return nBorrows;
      }
    } else {
      cout << transactionType << " is not a valid transaction type." << endl;
    }

  } else if (movieType == 'C') {
    vector<string> secondLineOfCommand;
    stringstream ss2(temp);
    string intermediate2;
    while (getline(ss2, intermediate2, ' ')) {
      secondLineOfCommand.push_back(intermediate2);
    }
    //int releaseMonth = stoi(secondLineOfCommand[0]);
    int releaseYear = stoi(secondLineOfCommand[1]);
    string actorFirstName = secondLineOfCommand[2];
    string actorLastName = secondLineOfCommand[3];
    if (transactionType == 'R') {
      int location = 0;

      for (int i = 0; i < movieInventory.at(mediaType).at(movieType).size();
           i++) {
        if ((movieInventory.at(mediaType)
                 .at(movieType)
                 .at(i)
                 ->GetFeaturedActorFirstName() == actorFirstName) &&
            (movieInventory.at(mediaType)
                 .at(movieType)
                 .at(i)
                 ->GetFeaturedActorLastName() == actorLastName) &&
            (movieInventory.at(mediaType)
                 .at(movieType)
                 .at(i)
                 ->GetReleaseYear() == releaseYear)) {
          movieInventory.at(mediaType).at(movieType).at(i)->SetStockAmount(
              movieInventory.at(mediaType)
                  .at(movieType)
                  .at(i)
                  ->GetStockAmount() +
              1);

          location = i;
          break;
        } else {
          location = -1;
        }
      }

      if (location == -1) {
        cout << releaseYear << " was not found in store's inventory." << endl;
      } else {

        if (customerList.Search(customerID) == nullptr) {
          cout << "Customer ID: " << customerID << " not found" << endl;
          return nullptr;
        }

        Returns* nReturns = new Returns(
            customerList.Search(customerID),
            movieInventory.at(mediaType).at(movieType).at(location));
        customerList.Search(customerID)->AddToHistory(nReturns);
        return nReturns;
      }
    }
    if (transactionType == 'B') {
      int location = 0;

      for (int i = 0; i < movieInventory.at(mediaType).at(movieType).size();
           i++) {
        if ((movieInventory.at(mediaType)
                 .at(movieType)
                 .at(i)
                 ->GetFeaturedActorFirstName() == actorFirstName) &&
            (movieInventory.at(mediaType)
                 .at(movieType)
                 .at(i)
                 ->GetFeaturedActorLastName() == actorLastName) &&
            (movieInventory.at(mediaType)
                 .at(movieType)
                 .at(i)
                 ->GetReleaseYear() == releaseYear)) {
          int stockAmount = movieInventory.at(mediaType)
                                .at(movieType)
                                .at(i)
                                ->GetStockAmount();
          if (stockAmount == 0) {
            cout << "Movie stock is " << stockAmount << "." << endl;
            return nullptr;
          }
          movieInventory.at(mediaType).at(movieType).at(i)->SetStockAmount(
              movieInventory.at(mediaType)
                  .at(movieType)
                  .at(i)
                  ->GetStockAmount() -
              1);

          location = i;
          break;
        } else {
          location = -1;
        }
      }

      if (location == -1) {
        cout << releaseYear << " was not found in store's inventory." << endl;
      } else {

        if (customerList.Search(customerID) == nullptr) {
          cout << "Customer ID: " << customerID << " not found" << endl;
          return nullptr;
        }

        Borrows* nBorrows = new Borrows(
            customerList.Search(customerID),
            movieInventory.at(mediaType).at(movieType).at(location));
        customerList.Search(customerID)->AddToHistory(nBorrows);

        return nBorrows;
      }
    }
  }
  return nullptr;
}
