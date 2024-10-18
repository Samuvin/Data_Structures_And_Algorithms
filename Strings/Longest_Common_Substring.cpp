#include<vector>
#include<iostream>
using namespace std;
int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	vector<vector<int>>dp(str1.size(), vector<int>(str2.size(), 0));
	int res = 0;
	for (int i = 0; i < str1.size(); i++)
	{
		for (int j = 0; j < str2.size(); j++)
		{
			if (str1[i] != str2[j])
				dp[i][j] = 0;
			else
			{
				if (i == 0 && j == 0)
					dp[i][j] = 1;
				else if (i == 0)
					dp[i][j] = 1 + dp[i][j - 1];
				else if (j == 0)
					dp[i][j] = 1 + dp[i - 1][j];
				else
					dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			res = max(res, dp[i][j]);
		}
	}
	cout << res << "\n";
}
