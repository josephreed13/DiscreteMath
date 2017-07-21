// estimate the probability that two integers selected at random 
// are relatively prime by testing a large number of randomly
// selected pairs of integers

#include <iostream>		// cout, cin
#include <ctime>		// time
#include <cstdlib>		// srand, rand 
using namespace std;

// Euclid's algorithm to determine if relatively prime
unsigned int gcd(unsigned int a, unsigned int b) {
	unsigned int x;
	while (b) {
		x = a % b;
		a = b;
		b = x;
	}
	return a;
}

// Random generator
int randomGen(int i) { 
 	return rand()%i;
}

int main() {
	int x, y, value;
	cout << "input x: ";
	cin >> x;
	cout << "input y: ";
	cin >> y;

	value = gcd(x,y);

	cout << "gcd returns: " << value << endl;

	if(value > 1) {
		cout << "x and y are not relatively prime" << endl;
	} else {
		cout << "x and y are relatively prime" << endl;
	}

	return 0;
}


// store thousands of results of tests in a large array
// 1 = yes
// 0 = no
// find percentage of 1's 
// compare percentage with Theorem 