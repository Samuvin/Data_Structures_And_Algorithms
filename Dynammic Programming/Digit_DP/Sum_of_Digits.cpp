//https://www.spoj.com/problems/CPCRC1C/

#include<bits/stdc++.h>
#define int long long
using namespace std;

string n;
int memo[10][2][90];

int dp(int index, bool last, int sum)
{
	if (index == n.size())
		return sum;

	int till = (last ? n[index] - '0' : 9);
	if (memo[index][last][sum] != -1)
		return memo[index][last][sum];
	int curr = 0;
	for (int digits = 0; digits <= till; digits++)
	{
		curr += dp(index + 1, last && (digits == till), sum + digits);
	}
	return memo[index][last][sum] = curr ;
}

int solve(int _n)
{
	memset(memo, -1, sizeof(memo));
	n = to_string(_n);
	return dp(0, true, 0);
}

signed main()
{

	while (1)
	{
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1)
			break;
		cout << solve(b) - solve(a - 1) << "\n";
	}
}
