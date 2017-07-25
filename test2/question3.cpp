// estimate the probability that two integers selected at random 
// are relatively prime by testing a large number of randomly
// selected pairs of integers

// store thousands of results of tests in a large array
// 1 = yes
// 0 = no
// find percentage of 1's 
// compare percentage with percentage from theorem (61%) 

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

void calculate(int size, int range) {
	int x, y, result;
	int a[size];

	for(int i = 0; i < size; i++) {
		// get random numbers for x and y
		x = rand() % range;
		y = rand() % range;
		
		// run x and y through Euclid's algorithm
		result = gcd(x,y);
		
		// result > 1, the numbers are not relatively prime
		if(result > 1) {
			a[i] = 0;
		// result = 1, the numbers are relatively prime
		} else {
			a[i] = 1;
		}
	}

	int count = 0;

	// count how many 1's are in the array
	for(int j = 0; j < size; j++) {
		if(a[j] > 0) {
			count++;
		}
	}

	cout << "For " << size << " pairs of randomly selected integers in the range of 1 to " << range << endl;
	// find ratio as decimal (double)
	double final = (double)count / size;
	// turn decimal into percentage 
	final = final * 100;
	cout << final << "% are relatively prime.\n";

	// compare with theorem's estimation (61%)
	double comparison = final - 61;
	if(comparison < 0)
		comparison = comparison * -1;

	cout << "That is " << comparison << " from the theorem's estimation (61%).\n\n";  

}

int main() {
	int size = 1000;
	int range = 1000;

	// run tests
	for(int i = 0; i < 3; i++) {
		calculate(size, range);
		// try different sizes
		size = size * 10;
	}
	
	return 0;
}
