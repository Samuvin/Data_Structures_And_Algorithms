#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool Subset_sum_Equals_To_k(vector<int> &arr, int ind, int target)
{
    if (target == 0)
        return true;
    if (ind == 0)
    {
        if (target == arr[ind])
            return true;
        else
            return false;
    }
    bool pick = false;
    if (arr[ind] <= target)
    {
        pick = Subset_sum_Equals_To_k(arr, ind - 1, target - arr[ind]);
    }
    bool notpick = Subset_sum_Equals_To_k(arr, ind - 1, target);
    return pick || notpick;
}
bool Subset_sum_Equals_To_k_Memo(vector<int> &arr, int ind, int target, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (ind == 0)
    {
        if (target == arr[ind])
            return true;
        else
            return false;
    }
    if (dp[ind][target] != -1)
        return dp[ind][target];
    bool pick = false;
    if (arr[ind] <= target)
    {
        pick = Subset_sum_Equals_To_k_Memo(arr, ind - 1, target - arr[ind], dp);
    }
    bool notpick = Subset_sum_Equals_To_k_Memo(arr, ind - 1, target, dp);
    return dp[ind][target] = pick || notpick;
}
bool Subset_sum_Equals_To_k_Tabulation(vector<int> &arr, int target)
{
    int row = arr.size();
    vector<vector<bool>> dp(row, vector<bool>(target + 1, false));
    for (int i = 0; i < row; i++)
    {
        dp[i][0] = true;
    }
    if (arr[0] <= target)
        dp[0][arr[0]] = true;
    for (int arr_ind = 1; arr_ind < row; arr_ind++)
    {
        for (int tar = 1; tar <= target; tar++)
        {
            bool pick = false;
            if (arr[arr_ind] <= tar)
            {
                int balance = tar - arr[arr_ind];
                pick = dp[arr_ind - 1][balance];
            }
            bool notpick = dp[arr_ind - 1][tar];
            dp[arr_ind][tar] = pick || notpick;
        }
    }
    return dp[row - 1][target];
}
bool Subset_sum_Equals_To_k_Space_Optimisation(vector<int> &arr, int target)
{
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    if (arr[0] <= target)
    {
        dp[arr[0]] = true;
    }
    for (int arr_ind = 1; arr_ind < arr.size(); arr_ind++)
    {
        vector<bool> curr(target + 1, false);
        curr[0] = true;
        for (int tar = 1; tar <= target; tar++)
        {
            bool pick = false;
            if (arr[arr_ind] <= tar)
            {
                int balance = tar - arr[arr_ind];
                pick = dp[balance];
            }
            bool notpick = dp[tar];
            curr[tar] = pick || notpick;
        }
        dp = curr;
    }
    return dp[target];
}
bool SubsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(arr.size(), vector<int>(k + 1, -1));
    if (Subset_sum_Equals_To_k(arr, n - 1, k))
        cout << "Subset with the given target found\n";
    else
        cout << "Subset with the given target not found\n";

    if (Subset_sum_Equals_To_k_Memo(arr, n - 1, k, dp))
        cout << "Subset with the given target found\n";
    else
        cout << "Subset with the given target not found\n";

    if (Subset_sum_Equals_To_k_Tabulation(arr, k))
        cout << "Subset with the given target found\n";
    else
        cout << "Subset with the given target not found\n";

    if (Subset_sum_Equals_To_k_Space_Optimisation(arr, k))
        cout << "Subset with the given target found\n";
    else
        cout << "Subset with the given target not found\n";
}
int main()
{
    int size, target;
    cin >> size >> target;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    SubsetSumToK(size, target, arr);
}
