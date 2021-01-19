#pragma once
#include "customer.h"
#include "movie.h"

class Returns : public Transactions {
 public:
  Returns(Customer* customerPtr, Movie* moviePtr);
  ~Returns();

  void Print() const;

private:
  Customer* nCustomerPtr;
  Movie* nMoviePtr;
};
