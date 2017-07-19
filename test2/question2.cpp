// given a positive integer n, 
// generate a random permutation of the set {1,2,3,...n}
#include <iostream>     // cout
#include <algorithm>    // random_shuffle
#include <vector>       // vector
#include <ctime>        // time
#include <cstdlib>      // rand, srand
using namespace std;

// function for random generator
int randomGen(int i) { 
  return rand()%i;
}

// main 
int main () {
  // capture srand at start of program
  srand(unsigned(time(0)));

  // variable declarations
  vector<int> set;
  int size;

  // UI 
  cout << "Give a size (n) of the set: ";
  cin >> size;
  // increment size to include last element in for loop
  // since we are starting at 1 instead of 0
  size++;

  // populate vector
  for(int i = 1; i < size; i++) {
    set.push_back(i); // {1,2,3,...n}
  }

  // pass the first & last elements, and the randomGen function into random_shuffle
  // random_shuffle: http://www.cplusplus.com/reference/algorithm/random_shuffle/
  random_shuffle (set.begin(), set.end(), randomGen);

  // print out content:
  cout << "A random permutation is: ";
  for (vector<int>::iterator it=set.begin(); it!=set.end(); it++) {
    cout << ' ' << *it;
  }
  cout << '\n';

  return 0;
}