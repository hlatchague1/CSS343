#pragma once

#include <string>
#include <vector>
#include "transactions.h"

using namespace std;

class Transactions;
class Customer {
 public:
  Customer();
  Customer(int id, string fName, string lName);
  ~Customer();

  int GetID();
  string GetFirstName();
  string GetLastName();
  vector<Transactions *> GetHistory();

  void SetID(int iD);
  void SetFirstName(int fName);
  void SetLastName(int lName);

  bool AddToHistory(Transactions *nTransaction);

 private:
  int customerID;
  string firstName;
  string lastName;
  vector<Transactions *> history;
};