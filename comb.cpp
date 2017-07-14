#include <iostream>

const int N = 5;

int sol[N];
int sum = 0;
int nr_of_elements;

void back(int lastElement)
{
    if (sum == N)
    {
        for (int i = 0 ; i < nr_of_elements; i++)
            std :: cout << sol[i] << " ";
        std :: cout << "\n";
        return ;
    }
    for ( int i = lastElement ; i <= N - sum ; i++)
    {
        sum += i;
        sol[nr_of_elements++] = i;
        back(i);
        sum -= i;
        nr_of_elements--;
    }
}

int main ()
{
    back(1);
    return 0;
}
