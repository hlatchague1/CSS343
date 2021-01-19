#include "borrows.h"

// overlaoded constructor
Borrows::Borrows(Customer* customerPtr, Movie* moviePtr) {
  nCustomerPtr = customerPtr;
  nMoviePtr = moviePtr;
}

Borrows::~Borrows() = default;

// function prints out borrows object
// when history gets called
void Borrows::Print() const {
  cout << "B, " << nCustomerPtr->GetID() << ", " << nMoviePtr->GetMovieTitle()
       << ", " << nMoviePtr->GetReleaseYear() << endl;
}

// returns borrower's customer pointer
Customer* Borrows::GetCustomer() { return nCustomerPtr; }

// returns borrowed movie's movie pointer
Movie* Borrows::GetMovie() { return nMoviePtr; }

// returns borrowed movie's media type
char Borrows::GetMediaType() { return mediaType; }
