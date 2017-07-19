#include <iostream>
#include <string>

using namespace std;

int main(){

void WordPermutation(string, string);
string substr(int startIndex, int length); 

string word = "01234567";

WordPermutation("",word);

}

void WordPermutation(string prefix, string word)
{
 
    int n = word.length();    
    if (n == 0) { cout<< prefix <<endl; }
    else
    {
        for (int i = 0; i < n; i++)
        {
  WordPermutation(prefix + word[i],word.substr(0, i) + word.substr(i + 1, n - (i+1)));
        cout<< i << endl;






        }
    }
}
