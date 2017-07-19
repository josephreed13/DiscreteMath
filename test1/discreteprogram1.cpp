#include <vector>
#include <iostream>
 
using namespace std;
 
#define SET_SIZE 4
 
int set[] = {1, 2, 3, 4};
vector<vector<int> > all_combinations;
const int tuple_size = 3;
 
void recursive_comb(int step_val, int array_index, std::vector<int> tuple)
{
    if (step_val == 0)
    {
        all_combinations.push_back(tuple); //<==We have the final combination
        return;
    }
 
    for (int i = array_index; i < SET_SIZE; i++)
    {
        tuple.push_back(set[i]);
        recursive_comb(step_val - 1, i + 1, tuple);
        tuple.pop_back();
    }
 
    return;
}
 
void init_combinations()
{
    std::vector<int> tuple;
    tuple.reserve(tuple_size); //avoids needless allocations
    recursive_comb(tuple_size, 0, tuple);
}
 
int main()
{
    init_combinations();
    cout << "Total Combinations: " << all_combinations.size() << endl;
 
    for (int i=0; i < all_combinations.size(); i++)
    {
        cout << "{";
        for (int j=0; j < tuple_size; j++)
        {
            cout << all_combinations[i][j] << " ";
        }
        cout << "}" << endl;
    }
 
    return 0;
}
