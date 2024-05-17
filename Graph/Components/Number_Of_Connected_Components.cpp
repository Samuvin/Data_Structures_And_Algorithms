#include <iostream>
#include <vector>
using namespace std;

void DFS(int src, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &comp)
{
	visited[src] = true;
	comp.push_back(src);
	for (int nbr : adj[src])
	{
		if (!visited[nbr])
			DFS(nbr, adj, visited, comp);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int nodes, edges;
	cin >> nodes >> edges;
	vector<vector<int>> adj(nodes + 1);
	vector<bool> visited(nodes + 1, false);

	while (edges--)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> comp;
	int components = 0;
	for (int v = 1; v <= nodes; v++)
	{
		if (!visited[v])
		{
			components++;
			DFS(v, adj, visited, comp);
			for (int u : comp)
			{
				cout << u << " ";
			}
			cout << "\n";
			comp.clear();
		}
	}
	cout << "Total Components: " << components;
}
