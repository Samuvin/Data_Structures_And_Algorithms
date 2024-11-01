#include<iostream>
#include<cstring>
using namespace std;

int n, m, x;
string str1, str2, str3;
int dp[100][100][100];

int rec(int i, int j, int k)
{
	//return the LCS of a[i...n] & b[j....m] & c[k....x]
	//pruning
	if (i >= str1.size() || j >= str2.size() || k >= str3.size())
		return 0;
	//base case

	//cache check
	if (dp[i][j][k] != -1)
		return dp[i][j][k];
	//compute
	int ans = max(rec(i + 1, j, k), rec(i, j + 1, k));
	ans = max(ans, rec(i, j, k + 1));

	if (str1[i] == str2[j] && str2[j] == str3[k])
		ans = max(ans, rec(i + 1, j + 1, k + 1) + 1);
	//save and return
	return dp[i][j][k] = ans;
}

int main()
{
	cin >> n >> m >> x;
	cin >> str1 >> str2 >> str3;
	memset(dp, -1, sizeof(dp));
	cout << rec(0, 0, 0);
}
