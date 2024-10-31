// Find the subset of items that sum upto target
// Targert will be queries

/*
Step 1 -> Form 1
Step 2 -> Define state and meaning
          dp[i][s]=0/1 if a subset exits of sum t in level ... n with s already taken in 0 to level-1
step 3 -> Decide Transition

                      => don'take dp[i+1][s]
          dp[i][s]----1   | or operation either on satisfied return true
                      => take     dp[i+1][s+arr[i]]
step 4 -> Time Complexity
		  i-> 0 - n
		  s-> 0 - sum
		  => n*sum
*/

#include<iostream>
#include<cstring>
using namespace std;

int n;
int t;
int x[101];
int dp[105][10100];

int rec(int level, int taken)
{
	//pruning
	if (taken > t)
		return 0;
	//base case
	if (level > n)
	{
		if (t == taken)
			return 1;
		else
			return 0;
	}
	//cache check
	if (dp[level][taken] != -1)
		return dp[level][taken];
	//compute
	int ans = rec(level + 1, taken);
	ans = (ans | rec(level + 1, taken + x[level]));
	//save and return
	return dp[level][taken] = ans;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	cin >> t;
	memset(dp, -1, sizeof(dp));
	cout << rec(1, 0);
}
