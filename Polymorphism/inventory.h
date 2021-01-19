#include <map>
#include "transactions.h"

class Inventory : public Transactions {
 public:
  Inventory();
  ~Inventory();

  void Print(
      map<const char, map<const char, vector<Movie*>>> movieInventory) const;
};