// generate a list of 100 random permutations of the set 
// of the first 100 positive integers

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
  int numPer;

  // UI 
  cout << "How big is the set? ";
  cin >> size;
  // increment size to include last element in for loop
  // since we are starting at 1 instead of 0
  size++;

  cout << "How many permutations? ";
  cin >> numPer;
  cout << endl;
  // increment just as we did for size
  numPer++;

  // populate vector
  for(int i = 1; i < size; i++) {
    set.push_back(i); // {1,2,3,...n}
  }

  // pass the first & last elements, and the randomGen function into random_shuffle
  // random_shuffle: http://www.cplusplus.com/reference/algorithm/random_shuffle/
  for(int j = 1; j < numPer; j++) {
    random_shuffle (set.begin(), set.end(), randomGen);
    // print out content:
    cout << "PERMUTATION #" << j << endl;
    for (vector<int>::iterator it=set.begin(); it!=set.end(); it++) {
      cout << ' ' << *it;
    }
    cout << '\n' << endl;
  }

  return 0;
}