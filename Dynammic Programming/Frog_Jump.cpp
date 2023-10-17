#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int Frog_Jump_Memo(vector<int>&Heights, vector<int>&dp,int ind)
{
    if(ind==0)
    {
        return 0;
    }
    if(dp[ind]!=-1)
    {
        return dp[ind];
    }
    int Jump_1=abs(Heights[ind]-Heights[ind-1])+Frog_Jump_Memo(Heights,dp,ind-1);
    int Jump_2=INT_MAX;
    if(ind>1)
    {
        Jump_2=abs(Heights[ind]-Heights[ind-2])+Frog_Jump_Memo(Heights,dp,ind-2);
    }
    return dp[ind]=min(Jump_1,Jump_2);
}

int Frog_Jump_Tabulation(vector<int>&Heights, vector<int>&dp)
{
    dp[0]=0;
    for(int i=1;i<Heights.size();i++)
    {
        int Jump_1=abs(Heights[i]-Heights[i-1])+dp[i-1];
        int Jump_2=INT_MAX;
        if(i>1)
        {
            Jump_2=abs(Heights[i]-Heights[i-2])+dp[i-2];
        }
        dp[i]=min(Jump_1,Jump_2);
    }
    return dp[Heights.size()-1];
}

int Frog_Jump_Space_Optimization(vector<int>&Heights)
{
    int prev_1=0;
    int prev_2=0;
    int ans=0;
    for(int i=1;i<Heights.size();i++)
    {
        int jump1=INT_MAX;
        int jump2=INT_MAX;
        jump1=abs(Heights[i]-Heights[i-1])+prev_1;
        if(i>1)
        {
            jump2=abs(Heights[i]-Heights[i-2])+prev_2;
        }
        int current=min(jump1,jump2);
        prev_2=prev_1;
        prev_1=current;
    }
    return prev_1;
}

int main()
{
    int size;
    cin>>size;
    vector<int>heights(size);
    vector<int>dp(size,-1);
    for(int i=0;i<size;i++)cin>>heights[i];
    cout<<Frog_Jump_Memo(heights,dp,size-1)<<"\n";
    cout<<Frog_Jump_Tabulation(heights,dp)<<"\n";
    cout<<Frog_Jump_Space_Optimization(heights)<<"\n";
}
