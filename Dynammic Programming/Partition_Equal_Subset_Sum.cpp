#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool Partition_Equal_Subset_Sum(vector<int> &nums, int ind, int target)
{
    if (target == 0)
        return true;
    if (ind == 0)
    {
        if (target == 0 || nums[ind] == target)
        {
            return true;
        }
        else
            return false;
    }
    bool pick = false;
    if (nums[ind] <= target)
    {
        pick = Partition_Equal_Subset_Sum(nums, ind - 1, target - nums[ind]);
    }
    bool notpick = Partition_Equal_Subset_Sum(nums, ind - 1, target);
    return pick || notpick;
}
bool Partition_Equal_Subset_Sum_Memo(vector<int> &nums, int ind, int target, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (ind == 0)
    {
        if (target == 0 || target == nums[ind])
            return true;
        else
            return false;
    }
    if (dp[ind][target] != -1)
        return dp[ind][target];
    bool pick = false;
    if (nums[ind] <= target)
    {
        pick = Partition_Equal_Subset_Sum_Memo(nums, ind - 1, target - nums[ind], dp);
    }
    bool notpick = Partition_Equal_Subset_Sum_Memo(nums, ind - 1, target, dp);
    return dp[ind][target] = pick || notpick;
}
bool Partition_Equal_Subset_Sum_Tabulation(vector<int> &arr, int target)
{
    int size = arr.size();
    vector<vector<bool>> dp(size, vector<bool>(target + 1, false));
    for (int base_case = 0; base_case < size; base_case++)
    {
        dp[base_case][0] = true;
    }
    if (arr[0] <= target)
    {
        dp[0][arr[0]] = true;
    }
    for (int arr_ind = 1; arr_ind < size; arr_ind++)
    {
        for (int targ = 1; targ <= target; targ++)
        {
            bool pick = false;
            if (arr[arr_ind] <= targ)
            {
                int balance = targ - arr[arr_ind];
                pick = dp[arr_ind - 1][balance];
            }
            bool notpick = dp[arr_ind - 1][targ];
            dp[arr_ind][targ] = pick || notpick;
        }
    }
    return dp[size - 1][target];
}
bool Partition_Equal_Subset_Space_Optimisation(vector<int> &arr, int target)
{
    int size = arr.size();
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    if (arr[0] <= target)
        dp[arr[0]] = true;
    for (int arr_ind = 1; arr_ind < size; arr_ind++)
    {
        vector<bool> curr(target + 1, false);
        curr[0] = true;
        for (int targ = 1; targ <= target; targ++)
        {
            bool pick = false;
            if (arr[arr_ind] <= targ)
            {
                int balance = targ - arr[arr_ind];
                pick = dp[balance];
            }
            bool notpick = dp[targ];
            curr[targ] = pick || notpick;
        }
        dp = curr;
    }
    return dp[target];
}
bool CanPartition(vector<int> &nums)
{
    int size = nums.size();
    int total_sum = accumulate(nums.begin(), nums.end(), 0);
    if ((total_sum & 1))
        return false;
    int target = total_sum / 2;
    vector<vector<int>> dp(size, vector<int>(target + 1, -1));
    return Partition_Equal_Subset_Space_Optimisation(nums, target);
    return Partition_Equal_Subset_Sum_Tabulation(nums, target);
    return Partition_Equal_Subset_Sum_Memo(nums, size - 1, target, dp);
    return Partition_Equal_Subset_Sum(nums, size - 1, target);
}
int main()
{
    int size;
    cin>>size;
    vector<int>v(size);
    for(int i=0;i<size;i++)cin>>v[i];
    CanPartition(v);
}
