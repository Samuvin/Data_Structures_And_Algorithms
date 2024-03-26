#include <iostream>
#include <vector>
#include <list>
using namespace std;
class Graph
{
    int vertex;
    list<int> *adj_list;

public:
    Graph(int vertex_count)
    {
        vertex = vertex_count;
        adj_list = new list<int>[vertex + 1];
    }
    void Add_Edge(int u, int v, bool isdirected = false)
    {
        adj_list[u].push_back(v);
        if (isdirected)
        {
            adj_list[v].push_back(u);
        }
    }

    void Print_Graph()
    {
        for (int i = 1; i <= vertex; i++)
        {
            cout << i << "-> ";
            for (auto nodes : adj_list[i])
            {
                cout << nodes << " ";
            }
            cout << "\n";
        }
    }
};
int main()
{
    Graph g(7);
    g.Add_Edge(1, 2);
    g.Add_Edge(2, 3);
    g.Add_Edge(1, 4);
    g.Add_Edge(4, 5);
    g.Add_Edge(5, 6);
    g.Add_Edge(6, 7);
    g.Add_Edge(5, 2);
    g.Add_Edge(7, 3);
    g.Print_Graph();
}
