#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h> 
int Knapsack(vector<int> weight, vector<int> value, int ind, int maxWeight)
{
	if(ind==0)
	{
		if(weight[0]<=maxWeight)
			return value[0];
		else
			return 0;
	}
	int Notpick=0+Knapsack(weight,value,ind-1,maxWeight);
	int pick=INT_MIN;
	if(weight[ind]<=maxWeight)
	{
		pick=value[ind]+Knapsack(weight,value,ind-1,maxWeight-weight[ind]);
	}
	return max(pick,Notpick);
}
int Knapsack_Memo(vector<int> weight, vector<int> value, int ind, int maxWeight,vector<vector<int>>&dp)
{

	if(ind==0)
	{
		if(weight[0]<=maxWeight)
		{
			return value[0];
		}
		else
			return 0;
	}
	if(dp[ind][maxWeight]!=-1)
		return dp[ind][maxWeight];

	int Notpick=0+Knapsack_Memo(weight,value,ind-1,maxWeight,dp);
	int pick=0;
	if(weight[ind]<=maxWeight)
	{
		pick=value[ind]+Knapsack_Memo(weight,value,ind-1,maxWeight-weight[ind],dp);
	}
	return dp[ind][maxWeight]=max(pick,Notpick);
}
int knapsack_Tabulation(vector<int> weight, vector<int> value, int maxWeight)
{
	int size=weight.size();
	vector<vector<int>>dp(weight.size(),vector<int>(maxWeight+1,0));
	for(int i=weight[0];i<=maxWeight;i++)
	{
		dp[0][i]=value[0];
	}
	for(int index=1;index<weight.size();index++)
	{
		for(int sack=0;sack<=maxWeight;sack++)
		{
			int notpick=dp[index-1][sack];
			int pick=0;
			if(weight[index]<=sack)
			{
				pick=value[index]+dp[index-1][sack-weight[index]];
			}
			dp[index][sack]=max(pick,notpick);
		}
	}
	return dp[size-1][maxWeight];
}
int knapsack_Space_Optimisation(vector<int> weight, vector<int> value, int maxWeight)
{
	int size=weight.size();
	vector<int>dp(maxWeight+1,0);
	for(int i=weight[0];i<=maxWeight;i++)
	{
		dp[i]=value[0];
	}
	for(int index=1;index<size;index++)
	{
		vector<int>curr(maxWeight+1,0);
		for(int sack=0;sack<=maxWeight;sack++)
		{
			int notpick=dp[sack];
			int pick=0;
			if(weight[index]<=sack)
			{
				pick=value[index]+dp[sack-weight[index]];
			}
			curr[sack]=max(pick,notpick);
		}
		dp=curr;
	}
	return dp[maxWeight];
}
int knapsack_Space_Optimisation_II(vector<int> weight, vector<int> value, int maxWeight)
{
	int size=weight.size();
	vector<int>dp(maxWeight+1,0);
	for(int i=weight[0];i<=maxWeight;i++)
	{
		dp[i]=value[0];
	}
	for(int index=1;index<size;index++)
	{
		for(int sack=maxWeight;sack>=0;sack--)
		{
			int pick=0;
			if(weight[index]<=sack)
			{
				pick=value[index]+dp[sack-weight[index]];
			}
			int notpick=dp[sack];
			dp[sack]=max(pick,notpick);
		}
	}
	return dp[maxWeight];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
	cout<< knapsack_Space_Optimisation_II(weight,value,maxWeight)<<"\n";
	cout<< knapsack_Space_Optimisation(weight,value,maxWeight)<<"\n";
	cout<< knapsack_Tabulation(weight,value,maxWeight)<<"\n";
	cout<< Knapsack_Memo(weight,value,n-1,maxWeight,dp)<<"\n";
	cout<< Knapsack(weight,value,n-1,maxWeight)<<"\n";
}
int main()
{
    int size,sacksize;
    cin>>size>>sacksize;
    vector<int>weight(size);
    vector<int>value(size);
    for(int i=0;i<size;i++)
    {
        cin>>weight[i];
    }
    for(int i=0;i<size;i++)
    {
        cin>>value[i];
    }
    knapsack(weight,value,size,sacksize);
}
