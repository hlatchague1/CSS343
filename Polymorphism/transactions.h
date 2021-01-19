#pragma once

#include "customer.h"
#include "movie.h"
#include <iostream>

class Customer;
class Transactions {
public:
  Transactions();
  ~Transactions();

  virtual void Print(vector<Transactions *> customerHistory) const;
  virtual void Print() const;

 protected:
  char transactionType = ' ';
  Customer *customerPtr = nullptr;
  char mediaType = ' ';
  Movie *moviePtr = nullptr;
};