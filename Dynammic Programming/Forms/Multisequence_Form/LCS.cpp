#include<iostream>
#include<cstring>
using namespace std;

int n, m;
string str1, str2;
int dp[10000][10000];

int rec(int i, int j)
{
	//return the LCS of a[i...n] & b[j....m]
	//pruning
	if (i >= str1.size() || j >= str2.size())
		return 0;
	//base case

	//cache check
	if (dp[i][j] != -1)
		return dp[i][j];
	//compute
	int ans = max(rec(i + 1, j), rec(i, j + 1));
	if (str1[i] == str2[j])
		ans = max(ans, rec(i + 1, j + 1) + 1);
	//save and return
	return dp[i][j] = ans;
}

int main()
{
	cin >> n >> m;
	cin >> str1 >> str2;
	memset(dp, -1, sizeof(dp));
	cout << rec(0, 0);
}
