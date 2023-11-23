#include <iostream>
#include <vector>
using namespace std;

int Coin_Change_Recursive(vector<int> &coins, int amount, int ind)
{
    if (ind == 0)
    {
        return (amount % coins[0] == 0);
    }
    int notpick = Coin_Change_Recursive(coins, amount, ind - 1);
    int pick = 0;
    if (coins[ind] <= amount)
    {
        pick = Coin_Change_Recursive(coins, amount - coins[ind], ind);
    }
    return pick + notpick;
}
int Coin_Change_Memo(vector<int> &coins, int amount, int ind, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return (amount % coins[0] == 0);
    }
    if (dp[ind][amount] != -1)
        return dp[ind][amount];
    int notpick = Coin_Change_Memo(coins, amount, ind - 1, dp);
    int pick = 0;
    if (coins[ind] <= amount)
    {
        pick = Coin_Change_Memo(coins, amount - coins[ind], ind, dp);
    }
    return dp[ind][amount] = pick + notpick;
}
int Coin_Change_Tabulation(vector<int> &coins, int amount)
{
    int size = coins.size();
    vector<vector<int>> dp(size, vector<int>(amount + 1, 0));
    for (int base_case = 0; base_case <= amount; base_case++)
    {
        dp[0][base_case] = (base_case % coins[0] == 0);
    }
    for (int index = 1; index < size; index++)
    {
        for (int target = 0; target <= amount; target++)
        {
            int pick = 0;
            if (target >= coins[index])
            {
                pick = dp[index][target - coins[index]];
            }
            int notpick = dp[index - 1][target];
            dp[index][target] = pick + notpick;
        }
    }
    return dp[size - 1][amount];
}
int Coin_Change_Space_Optimisation(vector<int> &coins, int amount)
{
    int size = coins.size();
    vector<int> dp(amount + 1, 0);
    for (int base_case = 0; base_case <= amount; base_case++)
    {
        dp[base_case] = (base_case % coins[0] == 0);
    }
    for (int index = 1; index < size; index++)
    {
        vector<int> curr(amount + 1, 0);
        for (int target = 0; target <= amount; target++)
        {
            int pick = 0;
            if (target >= coins[index])
            {
                pick = curr[target - coins[index]];
            }
            int notpick = dp[target];
            curr[target] = pick + notpick;
        }
        dp = curr;
    }
    return dp[amount];
}
int Coin_Change(int amount, vector<int> &coins)
{
    int size = coins.size();
    vector<vector<int>> dp(size, vector<int>(amount + 1, -1));
    cout << Coin_Change_Space_Optimisation(coins, amount) << "\n";
    cout << Coin_Change_Tabulation(coins, amount) << "\n";
    cout << Coin_Change_Memo(coins, amount, size - 1, dp) << "\n";
    cout << Coin_Change_Recursive(coins, amount, size - 1) << "\n";
}

int main()
{
    int size, amount;
    cin >> size >> amount;
    vector<int> coins(size);
    for (int i = 0; i < size; i++)
    {
        cin >> coins[i];
    }
    Coin_Change(amount, coins);
}
