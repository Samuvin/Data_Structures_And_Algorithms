#include<iostream>
#include<cstring>
using namespace std;

int dp[1000];

int rec(int x)
{
	if (x == 0)
		return 0;
	if (dp[x] != -1)
		return dp[x];
	int ans = 0;
	for (int m = 0; (1LL << m) <= x; m++)
	{
		if (rec(x - (1LL << m)) == 0)
		{
			ans = 1;
			break;
		}
	}
	return dp[x] = ans;
}

int main()
{
	int n;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i <= 20 ; i++)
		cout << i << " " << rec(i) << "\n";
}
