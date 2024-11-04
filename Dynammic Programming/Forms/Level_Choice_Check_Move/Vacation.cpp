/*

Form 1 - Level Choice Check Move

*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
vector<vector<int>>vacation;
vector<vector<int>>dp;

int memo(int level, int prev)
{
	//Pruning
	if (level >= N)
		return 0;
	//Base Case

	//Cache Check
	int &ans = dp[level][prev + 1];
	if (ans != -1)
		return ans;
	//Compute
	for (int Choice = 0; Choice < 3; Choice++)
	{
		//Check
		if (Choice != prev)
		{
			ans = max(ans, memo(level + 1, Choice) + vacation[level][Choice]);
		}
	}
	//Save and return
	return ans;
}

int main()
{
	cin >> N;
	vacation = vector<vector<int>>(N, vector<int>(3, 0));
	dp = vector<vector<int>>(N, vector<int>(4, -1));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> vacation[i][j];
	}
	cout << memo(0, -1);
}
