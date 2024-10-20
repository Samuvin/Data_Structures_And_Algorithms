class Solution {
public:
	vector<bool> vis;
	vector<vector<int>> adj;

	vector<long long>forward;
	vector<long long>backward;
	vector<long long>pow;
	vector<long long>len;

	const long long int RADIX1 = 911;
	const long long int MOD_1 = 1e9 + 7;

	void dfs(int src, string &s)
	{
		len[src] = 1;
		long long val = 0;

		for (int i : adj[src])
		{
			dfs(i, s);
			forward[src] = ((forward[src] * pow[len[i]]) % MOD_1 + forward[i]) % MOD_1;
			len[src] += len[i];
		}

		forward[src] = (forward[src] * RADIX1 + (s[src] - 'a' + 1)) % MOD_1;
		backward[src] = s[src] - 'a' + 1;

		for (int node = adj[src].size() - 1; node >= 0; node--)
		{
			int child = adj[src][node];
			backward[src] = (backward[src] * pow[len[child]] + backward[child]) % MOD_1;
		}
	}

	vector<bool> findAnswer(vector<int>& parent, string s)
	{
		int n = s.size();
		vis = vector<bool>(n, false);
		forward.assign(s.size(), 0);
		backward.assign(s.size(), 0);
		adj.assign(n, vector<int>());
		pow.assign(s.size(), 0);
		len.assign(s.size(), 0);

		pow[0] = 1;
		for (int i = 1; i < s.size(); i++)
		{
			pow[i] = (pow[i - 1] * RADIX1) % MOD_1;
		}

		for (int i = 1; i < parent.size(); i++)
		{
			adj[parent[i]].push_back(i);
		}

		dfs(0, s);

		for (int i = 0; i < s.size(); i++)
			vis[i] = (forward[i] == backward[i]);
		return vis;
	}
};
