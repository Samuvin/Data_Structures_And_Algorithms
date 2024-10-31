// Find the subset of items that sum upto target
// 1.Targert will be queries

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
		cout << rec(1, t) << endl;
	}
}


// For each query we have to clear the dp array because we are changing some states
// state Modeling
// We can also keep how much we took as a state
// we can also keep how much we want more to reach the sum
// Dp[level][sum_left]= 0/1 is possible or not
