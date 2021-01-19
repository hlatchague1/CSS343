#pragma once
#include "customer.h"

class HashTable {
 public:
  HashTable();
  ~HashTable();

  int HashFunction(int key);
  bool Insert(int key, Customer *val);
  Customer *Search(int key);

 private:
  vector<int> key;  // customerID
  const int divisor = 97;
  vector<Customer *> values[97];  // links to customer
};