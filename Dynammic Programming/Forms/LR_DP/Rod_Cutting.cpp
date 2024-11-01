#include<iostream>
#include<cstring>
using namespace std;

int n;
int x[1000];
int dp[1000][1000];


int rec(int l, int r)
{
	//pruning

	//base case
	if (l + 1 == r)
		return 0;
	//cache check
	if (dp[l][r] != -1)
		return dp[l][r];
	//Compute
	int ans = 1e9;
	for (int p = l + 1; p < r; p++)
	{
		ans = min(ans, x[r] - x[l] + rec(l, p) + rec(p, r));
	}
	//save and return
	return dp[l][r] = ans;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	memset(dp, -1, sizeof(dp));
	cout << rec(0, n - 1);
}
