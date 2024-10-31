// Find the subset of items that sum upto target
// 1.Printing Solution

/*
Trace Back
      Trace the transitions that lead to the final value
      ->Recheck
      ->Backpointer
*/

#include<iostream>
#include<cstring>
using namespace std;

int n;
int t;
int x[101];
int dp[105][10100];

int rec(int level, int left)
{
	//pruning
	if (left < 0)
		return 0;
	//base case
	if (level > n)
	{
		if (left == 0)
			return 1;
		else
			return 0;
	}
	//cache check
	if (dp[level][left] != -1)
		return dp[level][left];
	//compute
	int ans = rec(level + 1, left);
	ans = (ans | rec(level + 1, left - x[level]));
	//save and return
	return dp[level][left] = ans;
}


void printset(int level, int left)
{
	//base case
	if (level > n)
		return;
	//Find the current transition
	if (rec(level + 1, left) == 1)
	{
		printset(level + 1, left);
	}
	else if (rec(level + 1, left - x[level]) == 1)
	{
		cout << x[level] << " ";
		printset(level + 1, left - x[level]);
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	memset(dp, -1, sizeof(dp));
	int q;
	cin >> q;
	while (q--)
	{
		cin >> t;
		if (rec(1, t))
		{
			printset(1, t);
			cout << "\n";
		}
		else
			cout << -1 << "\n";
	}
}
