#pragma once
#include "customer.h"
#include "movie.h"

class Borrows : public Transactions {
 public:
  Borrows(Customer* customerPtr, Movie* moviePtr);
  ~Borrows();

  Customer* GetCustomer();
  Movie* GetMovie();
  char GetMediaType();
  void Print() const;

 private:
  Customer* nCustomerPtr;
  Movie* nMoviePtr;
};
