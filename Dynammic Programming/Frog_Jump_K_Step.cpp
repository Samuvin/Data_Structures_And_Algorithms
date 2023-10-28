#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int Frog_Jump_K_Times_Memo(vector<int> &height, vector<int> dp, int ind, int k)
{
    if (ind == 0)
    {
        return 0;
    }
    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    int ans = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (ind-i >= 0)
        {
            int Energy = abs(height[ind] - height[ind-i]) + Frog_Jump_K_Times_Memo(height, dp, ind-i, k);
            ans = min(ans, Energy);
        }
    }
    return dp[ind]=ans;
}

int Frog_Jump_K_Times_Tabulation(vector<int> &height, vector<int> dp,int k)
{
    dp[0]=0;
    for(int i=1;i<height.size();i++)
    {
        int ans=INT_MAX;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            {
                int jump=abs(height[i] - height[i-j])+dp[i-j];
                ans=min(ans,jump);
            }
        }
        dp[i]=ans;
    }
    return dp[height.size()-1];
}

int main()
{
    int size, k;
    cin >> size >> k;
    vector<int> heights(size);
    vector<int> dp(size, -1);
    for (int i = 0; i < size; i++)
        cin >> heights[i];
    cout << Frog_Jump_K_Times_Memo(heights, dp, size - 1, k) << "\n";
    cout << Frog_Jump_K_Times_Tabulation(heights, dp, k) << "\n";
}
