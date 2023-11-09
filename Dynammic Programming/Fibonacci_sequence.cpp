#include<iostream>
#include<vector>
using namespace std;

/*
Time Complexity : O(N)
Space Complexity: O(N)+O(N)
*/
int Fibbo_Memo(int n,vector<int>&dp)
{
    if(n<=1)
    {
        return n;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    return dp[n]=Fibbo_Memo(n-1,dp)+Fibbo_Memo(n-2,dp);
}
/*
Time Complexity : O(N)
Space Complexity: O(N)
*/
int Fibbo_Tabulation(int n,vector<int>&dp)
{
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
/*
Time Complexity : O(N)
Space Complexity: O(1)
*/
long long Fibbo_Space_Optimization(long long n)
{
    long long prev1=0;
    long long prev2=1;
    long long current=0;
    for(int i=1;i<=n;i++)
    {
        current=prev1+prev2;
        prev2=prev1;
        prev1=current;
    }
    return prev1;
}

int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<Fibbo_Memo(n,dp)<<"\n";
    cout<<Fibbo_Tabulation(n,dp)<<"\n";
    cout<<Fibbo_Space_Optimization(n)<<"\n";
}
