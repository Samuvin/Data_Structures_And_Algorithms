#include<bits/stdc++.h>
using namespace std;

int n;
int arr[10000];
int dp[10000];

int rec(int level)
{
	//best LIS ending at level.

	//Pruning

	//Base Case
	if (level < 0 || level >= n)return 0;
	//Cache Check
	if (dp[level] != -1)
		return dp[level];
	//Compute
	int ans = 1;
	for (int prev_taken = 0; prev_taken < level; prev_taken++)
	{
		if (arr[prev_taken] < arr[level])
			ans = max(ans, 1 + rec(prev_taken));
	}
	//save and return
	return dp[level] = ans;
}



int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	memset(dp, -1, sizeof(dp));
	int best = 0;
	for (int i = 0; i < n; i++)
		best = max(best, rec(i));
	cout << best;
}
