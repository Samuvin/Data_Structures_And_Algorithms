class Solution {
public:
	vector<bool> isPalindrome;
	vector<vector<int>> adjacencyList;

	vector<long long> forwardHash;
	vector<long long> backwardHash;
	vector<long long> power;

	const long long int RADIX = 911;
	const long long int MOD = 1e9 + 7;

	int computeForwardHash(int node, string& s)
	{
		int subtreeLength = 1;
		for (int child : adjacencyList[node])
		{
			int childLength = computeForwardHash(child, s);
			forwardHash[node] = ((forwardHash[node] * power[childLength]) % MOD + forwardHash[child]) % MOD;
			subtreeLength += childLength;
		}
		forwardHash[node] = (forwardHash[node] * RADIX + (s[node] - 'a' + 1)) % MOD;
		return subtreeLength;
	}

	int computeBackwardHash(int node, string& s) {
		int subtreeLength = 1;
		backwardHash[node] = (backwardHash[node] + (s[node] - 'a' + 1)) % MOD;
		for (int idx = adjacencyList[node].size() - 1; idx >= 0; idx--)
		{
			int child = adjacencyList[node][idx];
			int childLength = computeBackwardHash(child, s);
			backwardHash[node] = ((backwardHash[node] * power[childLength]) % MOD + backwardHash[child]) % MOD;
			subtreeLength += childLength;
		}
		return subtreeLength;
	}

	vector<bool> findAnswer(vector<int>& parent, string s) {
		int n = s.size();
		isPalindrome = vector<bool>(n, false);
		forwardHash.assign(n, 0);
		backwardHash.assign(n, 0);
		adjacencyList.assign(n, vector<int>());
		power.assign(n, 0);

		power[0] = 1;
		for (int i = 1; i < n; i++)
		{
			power[i] = (power[i - 1] * RADIX) % MOD;
		}

		for (int i = 1; i < parent.size(); i++)
		{
			adjacencyList[parent[i]].push_back(i);
		}

		computeForwardHash(0, s);
		computeBackwardHash(0, s);

		for (int i = 0; i < n; i++)
			isPalindrome[i] = (forwardHash[i] == backwardHash[i]);
		return isPalindrome;
	}
};
