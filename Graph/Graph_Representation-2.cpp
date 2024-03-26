#include <iostream>
#include <vector>
#include <list>
using namespace std;
class Graph
{
    int vertex;
    vector<vector<int>> adj_mat;

public:
    Graph(int vertex_count)
    {
        vertex = vertex_count;
        adj_mat.resize(vertex_count + 1, vector<int>(vertex_count + 1, 0));
    }
    void Add_Edge(int u, int v, bool isdirected = false)
    {
        adj_mat[u][v] = 1;
        if (isdirected)
        {
            adj_mat[v][u] = 1;
        }
    }

    void Print_Graph()
    {
        for (int u = 1; u <= vertex; u++)
        {
            for (int v = 1; v <= vertex; v++)
            {
                cout << adj_mat[u][v] << " ";
            }
            cout << "\n";
        }
    }
};
int main()
{
    Graph g(7);
    g.Add_Edge(1, 2, true);
    g.Add_Edge(2, 3, true);
    g.Add_Edge(1, 4, true);
    g.Add_Edge(4, 5, true);
    g.Add_Edge(5, 6, true);
    g.Add_Edge(6, 7, true);
    g.Add_Edge(5, 2, true);
    g.Add_Edge(7, 3, true);
    g.Print_Graph();
}
