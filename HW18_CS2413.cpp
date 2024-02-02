//
// ========================================
// HW18: Implement Graph, Graph Traverse
//       and Dijkstra's algorithm.
// ========================================
//
// In this assignment, we will implement an
// undirected graph, two traverse algorithms
// and the Dijkstra's algorithm.
//
// This template is based on matrix-based
// graph implementation, but you are free
// to work on list-based graph implementation.
//
// For simplicity, the template assumes no
// satellite data is used and focuses on
// dealing with integers (node numbers) only.
//
// Finally, feel free to modify the given template
// including the classes, functions, etc. Just make
// sure the outputs of functions tested in "main"
// stay the same (for auto-grading).
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Result
{
public:
    int length;
    int weight;
    int *path;

    Result(int l, int w, int *p);
};
Result::Result(int l, int w, int *p)
{
    length = l;
    weight = w;
    path = p;
}

// Please complete the graph class.
// Remember this is an undirected graph
// of "size" nodes labeled from 0 to size-1.
class Graph
{

private:
    // this variable holds the matrix
    int **m;

    // this variable holds the number of nodes in graph
    int size;

public:
    // this function returns the degree of node i
    int Degree(int i);

    // this function adds an edge between node i and
    // node j, and assigns a weight "w" to the edge
    //
    // recall: if we do not want a weighted graph,
    // simply set w = 1 for all edges
    //
    // you may also check boundary but in the testing
    // samples we assume all inputs are within boundary
    void Add(int i, int j, int w);

    // this function returns 1 if node i and
    // node j are connected and returns 0 otherwise.
    //
    // note: you can also let it return the weight;
    //       weight is zero if no edge exists
    int IsEdge(int i, int j);

    // this function returns 1 if there is a path
    // from node i to node j and returns 0 otherwise.
    int IsPath(int i, int j);

    // this function performs depth-first search
    // starting at node i. break any tie based on
    // node number (smaller node goes first) e.g.,
    // if you can pick node 2 or node 3, pick 2.
    // at last, this function should return an array
    // of size n holding the traverse sequence of nodes.
    // (Assume input graph is always connected.)
    int *DFT(int i);

    // this function performs breadth-first search
    // starting at node i. when exploring neighbors
    // of a set of nodes, explore them based on the
    // order of nodes in the queue.
    //
    // this means once you pop a node from the queue,
    // add its neighbors to the queue. (here, break
    // ties based on neighbor node numbers -- smaller
    // node gets added to the queue first)
    //
    // at last, this function should return an array
    // of size n holding the traverse sequence of nodes.
    int *BFT(int i);

    //
    // The following performs the Dijkstra's algorithm
    // to find the shorest path from node i to node j.
    //
    // It returns address of an object of the
    // Result class, which contains three
    // public variables (see definition at top):
    // (i) int length: length of the shorest path
    // (ii) int weight: total weight of the shortest path
    // (iii) int *path: array of nodes on the path
    // Example:
    // If the shortest path is 2 -> 3 -> 0, and
    // weight on (2,3) is 5 and weight on (3,0) is 1,
    // then path[0] = 2, path[1] = 3, path[2] = 0
    // and length = 3 and weight = 6.
    //
    Result *Dijkstra(int i, int j);

    // this is the constructor with input arguments
    // remember to allocate space for matrix "m" and
    // initialize all entries to zero
    //
    // Initialization is important because in "main"
    // we only add edges to the matrix and assume its
    // rest entries are zeros.
    Graph(int n);

    // Helper function for isPath using depth-first search
    bool isPathDFT(int i, int j, bool *visited);

    // Helper function for DFT
    void DFTHelp(int i, bool *visit, int *traverse, int &index);

    // Helper function for BFT
    void BFTHelp(int i, bool *visit, int *traverse, int &index);
};
Graph::Graph(int n) // Initalizes Graph class given a size parameter
{
    size = n;

    m = new int *[size];

    for (int i = 0; i < size; ++i)
    {
        m[i] = new int[size];
        for (int j = 0; j < size; ++j)
        {
            m[i][j] = 0;
        }
    }
}
int Graph::Degree(int n) // Returns the degree of a given node
{
    int degree = 0;
    for (int i = 0; i < size; ++i)
    {
        degree += m[n][i];
    }
    return degree;
}
void Graph::Add(int i, int j, int w) // Adds a node with a given weight
{
    m[i][j] = w;
    m[j][i] = w;
}
int Graph::IsEdge(int i, int j) // Returns the weight between two nodes and returns 0 if no edge connects them
{
    return m[i][j];
}
bool Graph::isPathDFT(int i, int j, bool *visit) // Returns true if there is a path between two nodes and false otherwise
{
    visit[i] = true;

    if (i == j)
    {
        return true;
    }

    for (int k = 0; k < size; ++k)
    {
        if (m[i][k] != 0 && !visit[k])
        {
            if (isPathDFT(k, j, visit))
            {
                return true;
            }
        }
    }

    return false;
}
int Graph::IsPath(int i, int j) // Returns 1 if there is a path between two nodes and 0 otherwise
{
    bool *visit = new bool[size];

    for (int k = 0; k < size; ++k)
    {
        visit[k] = false;
    }

    bool result = isPathDFT(i, j, visit);

    delete[] visit;

    if (result)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void Graph::DFTHelp(int i, bool *visit, int *traverse, int &index) // Creates an array using depth-first search
{
    visit[i] = true;
    traverse[index++] = i;

    int *neighbors = new int[size];
    int count = 0;
    for (int j = 0; j < size; ++j)
    {
        if (m[i][j] != 0 && !visit[j])
        {
            neighbors[count++] = j;
        }
    }

    sort(neighbors, neighbors + count);

    for (int j = 0; j < count; ++j)
    {
        if (!visit[neighbors[j]])
        {
            DFTHelp(neighbors[j], visit, traverse, index);
        }
    }

    delete[] neighbors;
}
int *Graph::DFT(int i) // Returns the array of the traversal using depth-first search
{
    bool *visit = new bool[size];
    for (int j = 0; j < size; ++j)
    {
        visit[j] = false;
    }

    int *traverse = new int[size];
    int index = 0;

    DFTHelp(i, visit, traverse, index);

    delete[] visit;

    return traverse;
}
void Graph::BFTHelp(int i, bool *visit, int *traverse, int &index) // Creates an array using breadth-first search
{
    queue<int> queue;
    visit[i] = true;
    queue.push(i);

    while (!queue.empty())
    {
        int curr = queue.front();
        queue.pop();

        traverse[index++] = curr;

        int *neighbors = new int[size];
        int count = 0;
        for (int j = 0; j < size; ++j)
        {
            if (m[curr][j] != 0 && !visit[j])
            {
                neighbors[count++] = j;
            }
        }

        sort(neighbors, neighbors + count);

        for (int j = 0; j < count; ++j)
        {
            visit[neighbors[j]] = true;
            queue.push(neighbors[j]);
        }

        delete[] neighbors;
    }
}
int *Graph::BFT(int i) // Returns the array of the traversal using breadth-first search
{
    bool *visit = new bool[size];
    for (int j = 0; j < size; ++j)
    {
        visit[j] = false;
    }

    int *traverse = new int[size];
    int index = 0;

    BFTHelp(i, visit, traverse, index);

    delete[] visit;

    return traverse;
}
Result *Graph::Dijkstra(int i, int j) // Returns the address of the result of the Dijkstra algorithm
{
    int *dist = new int[size];
    int *prev = new int[size];
    bool *visit = new bool[size];

    for (int k = 0; k < size; ++k)
    {
        dist[k] = 0x7FFFFFFF;
        prev[k] = -1;
        visit[k] = false;
    }

    dist[i] = 0;

    for (int k = 0; k < size; ++k)
    {
        int curr = -1;

        for (int l = 0; l < size; ++l)
        {
            if (!visit[l] && (curr == -1 || dist[l] < dist[curr]))
            {
                curr = l;
            }
        }

        visit[curr] = true;

        for (int l = 0; l < size; ++l)
        {
            int weight = m[curr][l];
            if (weight > 0 && dist[curr] + weight < dist[l])
            {
                dist[l] = dist[curr] + weight;
                prev[l] = curr;
            }
        }
    }

    int *path = new int[size];
    int length = 0;
    int curr = j;

    while (curr != -1)
    {
        path[length++] = curr;
        curr = prev[curr];
    }

    int *rev = new int[length];
    for (int k = 0; k < length; ++k)
    {
        rev[k] = path[length - k - 1];
    }

    int weight = dist[j];

    delete[] dist;
    delete[] prev;
    delete[] visit;
    delete[] path;

    return new Result(length, weight, rev);
}

int main()
{

    int mode, size, i, j, w;

    int a, b; // node numbers used for testing

    cin >> mode >> size >> a >> b;

    Graph x(size);

    // each time input a pair
    // of indices and a weight
    // remember to separate them
    // when inputing from keyboard
    // also, we assume inputs are
    // within boundary
    while (cin >> i >> j >> w)
    {
        x.Add(i, j, w);
    }

    // Mode 0: test IsEdge()
    if (mode == 0)
    {
        cout << x.IsEdge(a, b);
    }
    // Mode 1: test IsPath()
    else if (mode == 1)
    {
        cout << x.IsPath(a, b);
    }
    // Mode 2: test Degree()
    else if (mode == 2)
    {
        cout << x.Degree(a);
    }
    // Mode 3: test DFT()
    else if (mode == 3)
    {
        int *s = new int[size];
        s = x.DFT(a);
        for (int i = 0; i < size; i++)
        {
            cout << s[i];
        }
    }
    // Mode 4: test BFT()
    else if (mode == 4)
    {
        int *s = new int[size];
        s = x.BFT(a);
        for (int i = 0; i < size; i++)
        {
            cout << s[i];
        }
    }
    // Mode 5: test Dijkstra()
    else if (mode == 5)
    {
        Result *z = x.Dijkstra(a, b);
        cout << z->length << endl;
        cout << z->weight << endl;
        for (int i = 0; i < z->length; i++)
        {
            cout << z->path[i];
        }
    }

    return 0;
}
