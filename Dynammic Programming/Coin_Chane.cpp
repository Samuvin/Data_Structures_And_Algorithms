#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Minimum_Coins(vector<int> &coins, int amount, int ind)
{
    if (ind == 0)
    {
        if (amount % coins[ind] == 0)
        {
            return amount / coins[ind];
        }
        else
        {
            return 1e9;
        }
    }
    int pick = 1e9;
    if (coins[ind] <= amount)
    {
        pick = 1 + Minimum_Coins(coins, amount - coins[ind], ind);
    }
    int notpick = Minimum_Coins(coins, amount, ind - 1);
    return min(pick, notpick);
}
int Minimum_Coins_Memo(vector<int> &coins, int amount, int ind, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (amount % coins[0] == 0)
            return amount / coins[0];
        else
            return 1e9;
    }
    if (dp[ind][amount] != -1)
        return dp[ind][amount];
    int pick = 1e9;
    if (coins[ind] <= amount)
    {
        pick = 1 + Minimum_Coins_Memo(coins, amount - coins[ind], ind, dp);
    }
    int notpick = 0 + Minimum_Coins_Memo(coins, amount, ind - 1, dp);
    return dp[ind][amount] = min(pick, notpick);
}
int Minimum_Coins_Tabulation(vector<int> &coins, int amount)
{
    int size = coins.size();
    vector<vector<int>> dp(size, vector<int>(amount + 1, 0));
    for (int base_case = 0; base_case <= amount; base_case++)
    {
        if (base_case % coins[0] == 0)
        {
            dp[0][base_case] = base_case / coins[0];
        }
        else
        {
            dp[0][base_case] = 1e9;
        }
    }
    for (int ind = 1; ind < size; ind++)
    {
        for (int target = 0; target <= amount; target++)
        {
            int pick = 1e9;
            if (coins[ind] <= target)
            {
                pick = 1 + dp[ind][target - coins[ind]];
            }
            int notpick = 0 + dp[ind - 1][target];
            dp[ind][target] = min(pick, notpick);
        }
    }
    return dp[size - 1][amount];
}
int Minimum_Coins_Space_Optimisation(vector<int> &coins, int amount)
{
    int size = coins.size();
    vector<int> dp(amount + 1, 0);
    for (int base_case = 0; base_case <= amount; base_case++)
    {
        if (base_case % coins[0] == 0)
        {
            dp[base_case] = base_case / coins[0];
        }
        else
        {
            dp[base_case] = 1e9;
        }
    }
    for (int ind = 1; ind < size; ind++)
    {
        vector<int> curr(amount + 1, 0);
        for (int target = 0; target <= amount; target++)
        {
            int pick = 1e9;
            if (coins[ind] <= target)
            {
                pick = 1 + curr[target - coins[ind]];
            }
            int notpick = 0 + dp[target];
            curr[target] = min(pick, notpick);
        }
        dp = curr;
    }
    return dp[amount];
}
int CoinChange(vector<int> &coins, int amount)
{
    int ind = coins.size();
    vector<vector<int>> dp(ind, vector<int>(amount + 1, -1));
    int check = Minimum_Coins_Space_Optimisation(coins, amount);
    cout<< ((check >= 1e9 )? -1 : check)<<"\n";
    int check2=Minimum_Coins_Tabulation(coins,amount);
    cout<< ((check2>=1e9)?-1:check)<<"\n";
    int check3=Minimum_Coins_Memo(coins,amount,ind-1,dp);
    cout<< ((check3>=1e9)?-1:check)<<"\n";
    int check4=Minimum_Coins(coins,amount,ind-1);
    cout<<(check4>=1e9?-1:check)<<"\n";
}
int main()
{
    int size,amount;
    cin>>size>>amount;
    vector<int>coins(size);
    for(int i=0;i<size;i++)
    {
        cin>>coins[i];
    }
    CoinChange(coins,amount);
}
