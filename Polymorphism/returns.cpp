#include "returns.h"

// overlaoded constructor
Returns::Returns(Customer* customerPtr, Movie* moviePtr) {
  nCustomerPtr = customerPtr;
  nMoviePtr = moviePtr;
}

Returns::~Returns() = default;

// function prints out returns object
// when history gets called
void Returns::Print() const {
  cout << "R, " << nCustomerPtr->GetID() << ", " << nMoviePtr->GetMovieTitle()
       << ", " << nMoviePtr->GetReleaseYear() << endl;
}
