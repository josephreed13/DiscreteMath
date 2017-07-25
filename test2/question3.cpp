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

void calculate(int size, int range) {
	int x, y, result;
	int a[size];

	for(int i = 0; i < size; i++) {
		
		x = rand() % range;
		y = rand() % range;
		
		result = gcd(x,y);
		
		if(result > 1) {
			a[i] = 0;
		} else {
			a[i] = 1;
		}
	}

	int count = 0;

	for(int j = 0; j < size; j++) {
		if(a[j] > 0) {
			count++;
		}
	}

	cout << "For " << size << " pairs of randomly selected integers in the range of 1 to " << range << endl;
	double final = (double)count / size;
	final = final * 100;
	cout << final << "% are relatively prime.\n";

	double comparison = final - 61;
	if(comparison < 0)
		comparison = comparison * -1;

	cout << "That is " << comparison << " from the theorem's estimation (61%).\n\n";  

}

int main() {
	int size = 1000;
	int range = 1000;

	for(int i = 0; i < 3; i++) {
		calculate(size, range);
		size = size * 10;
	}
	return 0;
}


// store thousands of results of tests in a large array
// 1 = yes
// 0 = no
// find percentage of 1's 
// compare percentage with percentage from theorem (61%) 