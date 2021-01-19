#include "hashtable.h"

// empty hash table constructor
HashTable::HashTable() {}

HashTable::~HashTable() = default;

// creates the hash function
int HashTable::HashFunction(int key) { return key % divisor; }

// inserts a new customer pointer into
// the hashatable & returns true if it
// is successful
bool HashTable::Insert(int key, Customer *val) {
  int vectorIndex = HashFunction(key);
  if (vectorIndex < divisor) {
    this->key.push_back(key);
    this->values[vectorIndex].push_back(val);
    return true;
  }
  return false;
}

// searches for a customer using
// their customerID and returns a
// pointer to that customer if it
// it found
Customer *HashTable::Search(int key) {
  int vectorIndex = HashFunction(key);
  for (int i = 0; i < this->key.size(); i++) {
    if (this->key.at(i) == key) {
      for (int i = 0; i < values[vectorIndex].size(); i++) {
        if (values[vectorIndex].at(i)->GetID() == key) {
          return values[vectorIndex].at(i);
        }
      }
    }
  }
  return nullptr;
}
