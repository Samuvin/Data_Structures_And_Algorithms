#include<iostream>
#include<vector>
#include<stack>
using namespace std;


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int nodes, edges;
	cin >> nodes >> edges;
	vector<vector<int>>adj(nodes + 1);
	vector<bool>vis(nodes + 1);
	while (edges--)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int>visited(nodes + 1, 0);
	vector<int>comp;
	int components = 0;
	for (int v = 1; v <= nodes; v++)
	{
		if (!visited[v])
		{
			components++;

			auto DFS = [&](int src)
			{
				stack<int>st;
				st.push(src);
				while (!st.empty())
				{
					int parent = st.top();
					st.pop();
					visited[parent] = 1;
					comp.push_back(parent);
					for (auto nbr : adj[parent])
					{
						if (!visited[nbr])
						{
							st.push(nbr);
						}
					}
				}
			};

			DFS(v);

			for (int u : comp)
			{
				cout << u << " ";
			}
			cout << "\n";
			comp.clear();
		}
	}
	cout << "Total components :" << components;
}
