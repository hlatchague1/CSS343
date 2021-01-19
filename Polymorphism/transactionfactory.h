#include <sstream>
#include "customer.h"
#include "hashtable.h"
#include "movie.h"
#include "returns.h"
#include "borrows.h"
#include "inventory.h"
#include "history.h"
#include <map>
#include "classic.h"
#include "comedy.h"
#include "drama.h"


class TransactionFactory {
  friend class Classic;
 public:
  static Transactions* CreateTransaction(
      const string& commandLine, HashTable customerList,
      map<const char, map<const char, vector<Movie*>>> movieInventory);
  virtual ~TransactionFactory() = default;
};