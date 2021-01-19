#include "transactions.h"

Transactions::~Transactions() = default;

// virtual function to be implemented in classes
// who inherit from the transaction class
void Transactions::Print(vector<Transactions*> customerHistory) const {}

// virtual function to be implemented in classes
// who inherit from the transaction class
void Transactions::Print() const {}

// empty constructor
Transactions::Transactions() {}