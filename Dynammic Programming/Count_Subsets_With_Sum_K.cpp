#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
int Count_Subsets_With_Sum_K(vector<int> &arr, int target, int ind)
{
    if (ind == 0)
    {
        if (target == 0 && arr[ind] == 0)
            return 2;
        if (target == 0 || target == arr[ind])
            return 1;
        else
            return 0;
    }
    int pick = 0;
    if (arr[ind] <= target)
    {
        pick = Count_Subsets_With_Sum_K(arr, target - arr[ind], ind - 1);
    }
    int notpick = Count_Subsets_With_Sum_K(arr, target, ind - 1);
    return pick + notpick;
}

int Count_Subsets_With_Sum_K_Memo(vector<int> &arr, int target, int ind, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || target == arr[0])
            return 1;
        else
            return 0;
    }
    if (dp[ind][target] != -1)
        return dp[ind][target];
    int pick = 0;
    if (arr[ind] <= target)
        pick = Count_Subsets_With_Sum_K_Memo(arr, target - arr[ind], ind - 1, dp);
    int notpick = Count_Subsets_With_Sum_K_Memo(arr, target, ind - 1, dp);
    return dp[ind][target] = (pick + notpick) % MOD;
}

int Count_Subsets_With_Sum_K_Tabulation(vector<int> &arr, int target)
{
    int size = arr.size();
    vector<vector<int>> dp(size, vector<int>(target + 1, 0));
    for (int base_case = 0; base_case < size; base_case++)
    {
        dp[base_case][0] = 1;
    }
    if (arr[0] == 0)
    {
        dp[0][0] = 2;
    }
    if (arr[0] <= target)
        dp[0][arr[0]] = 1;
    for (int index = 1; index < size; index++)
    {
        for (int targ = 0; targ <= target; targ++)
        {
            int pick = 0;
            if (arr[index] <= targ)
            {
                pick = dp[index - 1][targ - arr[index]];
            }
            int notpick = dp[index - 1][targ];
            dp[index][targ] = (pick + notpick) % MOD;
        }
    }
    return dp[size - 1][target];
}

int Count_Subsets_With_Sum_K_Space_Optimisation(vector<int> &arr, int target)
{
    int size = arr.size();
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    if (arr[0] <= target)
        dp[arr[0]] = 1;
    if (arr[0] == 0)
        dp[0] = 2;
    for (int index = 1; index < size; index++)
    {
        vector<int> curr(target + 1, 0);
        curr[0] = 1;
        for (int targ = 0; targ <= target; targ++)
        {
            int pick = 0;
            if (arr[index] <= targ)
            {
                pick = dp[targ - arr[index]];
            }
            int notpick = dp[targ];
            curr[targ] = (pick + notpick) % MOD;
        }
        dp = curr;
    }
    return dp[target];
}

void FindWays(vector<int> &arr, int k)
{
    int size = arr.size();
    vector<vector<int>> dp(arr.size(), vector<int>(k + 1, -1));
    cout << Count_Subsets_With_Sum_K_Space_Optimisation(arr, k) << "\n";
    cout << Count_Subsets_With_Sum_K_Tabulation(arr, k) << "\n";
    cout << Count_Subsets_With_Sum_K_Memo(arr, k, size - 1, dp) << "\n";
    cout << Count_Subsets_With_Sum_K(arr, k, size - 1) << "\n";
}

int main()
{
    int size, target;
    cin >> size >> target;
    vector<int> res(size, 0);
    for (int i = 0; i < size; i++)
        cin >> res[i];
    FindWays(res, target);
}
