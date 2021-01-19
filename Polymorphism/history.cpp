#include "history.h"

using namespace std;

// overloaded constructor
History::History(Customer* customerPtr) { nCustomerPtr = customerPtr; }

History::~History() = default;

// prints out the customer's history vector
// if it's size is greater than 0
void History::Print(vector<Transactions*> customerHistory) const {
  if (!customerHistory.empty()) {
    cout << "History: " << endl;
  }
  for (int i = 0; i < customerHistory.size(); ++i) {
    customerHistory[i]->Print();
    cout << endl;
  }
}

// returns the customer pointer
Customer* History::GetCustomerPtr() { return nCustomerPtr; }
