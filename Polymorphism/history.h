#include "customer.h"

class History : public Transactions {
 public:
  History(Customer* customerPtr);
  ~History();

  void Print(vector<Transactions*> customerHistory) const;
  Customer *GetCustomerPtr();

 private:
  Customer* nCustomerPtr;
};