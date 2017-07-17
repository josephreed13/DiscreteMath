#include <bits/stdc++.h>
using namespace std;

// Iterative function to find longest decreasing subsequence
// of given array
void findLDS(int arr[], int n)
{
	// LDS[i] stores the longest decreasing subsequence of sub-array
	// arr[0..i] that ends with arr[i]
	vector<int> LDS[n];

	// LDS[0] denotes longest decreasing subsequence ending with arr[0]
	LDS[0].push_back(arr[0]);

	// start from second element in the array
	for (int i = 1; i < n; i++)
	{
		// do for each element in subarray arr[0..i-1]
		for (int j = 0; j < i; j++)
		{
			// find longest decreasing subsequence that ends with arr[j]
			// where arr[j] is more than the current element arr[i]

			if (arr[j] > arr[i] && LDS[j].size() > LDS[i].size())
				LDS[i] = LDS[j];
		}

		// include arr[i] in LDS[i]
		LDS[i].push_back(arr[i]);
	}

	// uncomment below lines to print contents of vector LDS
	/* for (int i = 0; i < n; i++)
    {
    	cout << "LDS[" << i << "] - ";
    	for (int j : LDS[i])
        	cout << j << " ";
        cout << endl;
    } */

	// j will contain index of LDS
	int j = 0;
	for (int i = 0; i < n; i++)
		if (LDS[j].size() < LDS[i].size())
			j = i;

	// print LDS
	for (int i : LDS[j])
		cout << i << " ";
}
void find_lis(vector<int> &a, vector<int> &b)
{
	vector<int> p(a.size());
	int u, v;
 
	if (a.empty()) return;
 
	b.push_back(0);
 
	for (size_t i = 1; i < a.size(); i++) 
        {
                // If next element a[i] is greater than last element of
                // current longest subsequence a[b.back()], just push it at back of "b" and continue
		if (a[b.back()] < a[i]) 
                {
			p[i] = b.back();
			b.push_back(i);
			continue;
		}
 
                // Binary search to find the smallest element referenced by b which is just bigger than a[i]
                // Note : Binary search is performed on b (and not a).
                // Size of b is always <=k and hence contributes O(log k) to complexity.    
		for (u = 0, v = b.size()-1; u < v;) 
                {
			int c = (u + v) / 2;
			if (a[b[c]] < a[i]) u=c+1; else v=c;
		}
 
                // Update b if new value is smaller then previously referenced value 
		if (a[i] < a[b[u]]) 
                {
			if (u > 0) p[i] = b[u-1];
			b[u] = i;
		}	
	}
 
	for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
}


// main function
int main()
{
	int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
	int a[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
	int n = sizeof(arr)/sizeof(arr[0]);
	vector<int> seq(a, a+sizeof(a)/sizeof(a[0])); 
	vector<int> lis;                              
        find_lis(seq, lis);
	for (size_t i = 0; i < lis.size(); i++)
		printf("%d ", seq[lis[i]]);
        printf("\n");	
	findLDS(arr, n);

	return 0;
}
