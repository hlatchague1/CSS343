/**
 * Testing ass4 movie store functions
 *
 * @author Hadassah Latchague, David Mehedinti
 * @date 3 Dec 2019
 */

#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include "moviestore.h"

using namespace std;

void TestStore() {
  cout << "=====================================" << endl;
  cout << "Start testStore" << endl;
  cout << endl;

  MovieStore blockbuster;
  blockbuster.ReadMovies("data4movies.txt");
  blockbuster.ReadCustomers("data4customers.txt");
  blockbuster.ReadCommands("data4commands.txt");

  cout << endl;
  cout << "End testStore" << endl;
  cout << "=====================================" << endl;
}


void TestAll() {
  TestStore();
}
