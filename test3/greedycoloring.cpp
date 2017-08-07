// Greedy Coloring algorithm

#include <iostream>
#include <list>
using namespace std;

class Graph {

    int numVert;    
    list<int> *adjacent;

public:
    Graph(int numVert)   { this->numVert = numVert; adjacent = new list<int>[numVert]; }
    ~Graph()       { delete [] adjacent; }
 
    void append(int numVert, int w);
 
    void greedyColoring();
};
 
void Graph::append(int numVert, int w)
{
    adjacent[numVert].push_back(w);
    adjacent[w].push_back(numVert);
}
 

void Graph::greedyColoring() {
    int result[numVert];
 
    result[0]  = 0;
 
    for (int u = 1; u < numVert; u++)
        result[u] = -1; 
 
    bool available[numVert];
    for (int cr = 0; cr < numVert; cr++)
        available[cr] = false;
 
    for (int u = 1; u < numVert; u++)
    {
        list<int>::iterator i;
        for (i = adjacent[u].begin(); i != adjacent[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = true;
 
        int cr;
        for (cr = 0; cr < numVert; cr++)
            if (available[cr] == false)
                break;
 
        result[u] = cr;
 
        for (i = adjacent[u].begin(); i != adjacent[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = false;
    }
 
    for (int u = 0; u < numVert; u++)
        cout << "numVertertex " << u << " --->  Color "
             << result[u] << endl;
}

int main()
{
    Graph q(5);
    q.append(0, 1);
    q.append(0, 2);
    q.append(1, 2);
    q.append(1, 3);
    q.append(2, 3);
    q.append(3, 4);
    cout << "Coloring of graph 1 \n";
    q.greedyColoring();
 
    Graph r(5);
    r.append(0, 1);
    r.append(0, 2);
    r.append(1, 2);
    r.append(1, 4);
    r.append(2, 4);
    r.append(4, 3);
    cout << "\nColoring of graph 2 \n";
    r.greedyColoring();
 
    return 0;
}