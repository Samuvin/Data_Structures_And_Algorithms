#include <bits/stdc++.h>
int solve(int n)
{
	if(n==1)
		return 0;
	int res=INT_MAX;
	if(n%2==0)
	{
		res=min(res,solve(n/2)+1);
	}
	if(n%3==0)
	{
		res=min(res,solve(n/3)+1);
	}
	return min(res,solve(n-1)+1);
} 
vector<int>dp;
int memo(int n)
{
	if(n==1)
		return 0;
	int &state=dp[n];
	if(state!=-1)
		return state;
	state=INT_MAX;
	if(n%2==0)
		state=min(state,memo(n/2)+1);
	if(n%3==0)
		state=min(state,memo(n/3)+1);
	return state=min(state,memo(n-1)+1);
}
int tab(int n)
{
	dp[1]=0;
	dp[0]=0;
	for(int i=2;i<=n;i++)
	{
		int curr=INT_MAX;
		if(i%2==0)
			curr=min(curr,dp[i/2]+1);
		if(i%3==0)
			curr=min(curr,dp[i/3]+1);
		dp[i]=min(curr,dp[i-1]+1);
	}
	return dp[n];
}
int countStepsToOne(int n) {
	dp.assign(n+1,-1);
	return tab(n);
}
