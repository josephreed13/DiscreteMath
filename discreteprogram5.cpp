// Program to print all permutations of a string in sorted order.
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
 
int compare(const void *a, const void * b)
{  return ( *(char *)a - *(char *)b ); }
 
// A utility function two swap two characters a and b
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
 
// This function finds the index of the smallest character
// which is greater than 'first' and is present in str[l..h]
int findCeil(int arr[], int first, int l, int h) {
    // initialize index of ceiling element
    int ceilIndex = l;
 
    // Now iterate through rest of the elements and find
    // the smallest character greater than 'first'
    for (int i = l+1; i <= h; i++)
      if (arr[i] > first && arr[i] < arr[ceilIndex])
            ceilIndex = i;
 
    return ceilIndex;
}
// Print all permutations of str in sorted order
void sortedPermutations( int arr[] , int s) {
    // Get size of string
    int size = s;
 
    // Sort the string in increasing order
    //qsort( arr, size, sizeof( arr[0] ), compare );
 
    // Print permutations one by one
    bool isFinished = false;
    while ( ! isFinished ) {
        // print this permutation
        for (int j = 0; j < s; j++) {
            cout << arr[j];
        }
        cout << endl;
 
        // Find the rightmost character which is smaller than its next
        // character. Let us call it 'first char'
        int i;
        for ( i = size - 2; i >= 0; --i )
           if (arr[i] < arr[i+1])
              break;
 
        // If there is no such chracter, all are sorted in decreasing order,
        // means we just printed the last permutation and we are done.
        if ( i == -1 )
            isFinished = true;
        else
        {
            // Find the ceil of 'first char' in right of first character.
            // Ceil of a character is the smallest character greater than it
            int ceilIndex = findCeil( arr, arr[i], i + 1, size - 1 );
 
            // Swap first and second characters
            swap( &arr[i], &arr[ceilIndex] );
 
            // Sort the string on right of 'first char'
            qsort( arr + i + 1, size - i - 1, sizeof(arr[0]), compare );
        }
    }
}

int main() {
    cout << "Enter the max value (n) of the set: ";
    
    int size;
    cin >> size;
    int arr[size];

    int j = 1;
    if (size > j) {
        for(int i = 0; i < size; i++) {
            arr[i] = j;
            j++;
        }
        
    } else {
        cout << "ERROR: the number must be greater than 0\n";
        return 0;
    }

    sortedPermutations(arr, size);
    return 0;
}