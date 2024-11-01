#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[10000][10000];
int dp[10000][10000];
bool done[10000][10000];
//grid can also contains negative values
//we keep a boolean state to make sure a state is computed or not
int rec(int r, int c)
{
	//Maximum path sum ending at r,c

	//pruning
	if (r < 0 || c < 0)
	{
		//not posible
		return -1e9;
	}
	//base case
	if (r == 0 && c == 0)
	{
		return arr[0][0];
	}
	//cache check
	if (done[r][c])
		return dp[r][c];
	//compute
	int ans = -1e9;
	ans = max(ans, rec(r - 1, c) + arr[r][c]);
	ans = max(ans, rec(r, c - 1) + arr[r][c]);
	//save and return
	done[r][c] = 1;
	return dp[r][c] = ans;
}



int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			done[i][j] = 0;
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << rec(n - 1, m - 1);
}
