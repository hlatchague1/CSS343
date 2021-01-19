#include "customer.h"

// empty customer constructor
Customer::Customer() {}

// oveerloaded customer constructor
// sets customer's name and ID
Customer::Customer(int id, string fName, string lName) {
  this->customerID = id;
  this->lastName = lName;
  this->firstName = fName;
}

Customer::~Customer() = default;

// returns the customer's ID
int Customer::GetID() { return customerID; }

// returns the customer's first name
string Customer::GetFirstName() { return firstName; }

// returns the customer's last name
string Customer::GetLastName() { return lastName; }

// returns customer's history vector
vector<Transactions *> Customer::GetHistory() { return history; }

// sets customer's ID
void Customer::SetID(int iD) { this->customerID = iD; }

// sets customer's first name
void Customer::SetFirstName(int fName) { this->firstName = fName; }

// sets customer's last name
void Customer::SetLastName(int lName) { this->lastName = lName; }

// adds to customer's history vector by pushing back
// the transaction that occured
bool Customer::AddToHistory(Transactions *nTransaction) {
  history.push_back(nTransaction);
  return true;
}
/* Maybe should check for duplicate transactions? What would be
    a valid fail condition? */