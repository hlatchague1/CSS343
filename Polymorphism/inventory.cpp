#include "inventory.h"

// empty constructor
Inventory::Inventory() {}

Inventory::~Inventory() = default;

// prints out the store's movie inventory
void Inventory::Print(
    map<const char, map<const char, vector<Movie*>>> movieInventory) const {
  char mediaType = 'D';
  vector<char> genres = {'C', 'F', 'D'};
  cout << "Inventory:" << endl;

  for (int i = 0; i < genres.size(); i++) {
    for (int j = 0; j < movieInventory.at(mediaType).at(genres[i]).size();
         j++) {
      cout << movieInventory.at(mediaType).at(genres[i]).at(j)->GetStockAmount()
           << ", "
           << movieInventory.at(mediaType).at(genres[i]).at(j)->GetMovieTitle()
           << ", "
           << movieInventory.at(mediaType).at(genres[i]).at(j)->GetReleaseYear()
           << ", "
           << movieInventory.at(mediaType)
                  .at(genres[i])
                  .at(j)
                  ->GetDirectorFirstName()
           << " "
           << movieInventory.at(mediaType)
                  .at(genres[i])
                  .at(j)
                  ->GetDirectorLastName()
           << endl;
    }
  }
}
