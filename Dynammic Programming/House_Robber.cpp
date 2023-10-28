#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int Maximum_Sum_of_Non_Adjacent_Memo(vector<int> &Houses, int ind, vector<int> &dp)
{
    if (ind == 0)
        return Houses[0];
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int pick = Houses[ind] + Maximum_Sum_of_Non_Adjacent_Memo(Houses, ind - 2, dp);
    int not_pick = 0 + Maximum_Sum_of_Non_Adjacent_Memo(Houses, ind - 1, dp);
    return dp[ind] = max(pick, not_pick);
}

int Maximum_Sum_of_Non_Adjacent_Tabulation(vector<int> &Houses)
{
    int size = Houses.size();
    vector<int> dp(size, 0);
    dp[0] = Houses[0];
    for (int i = 1; i < size; i++)
    {
        int notpick = 0 + dp[i - 1];
        int pick = Houses[i] + ((i - 2 >= 0) ? dp[i - 2] : 0);
        dp[i] = max(pick, notpick);
    }
    return dp[Houses.size() - 1];
}

int Maximum_Sum_of_Non_Adjacent_Space_Optimisation(vector<int> &Houses)
{
    int size = Houses.size();
    int prev = Houses[0];
    int second_prev = 0;
    for (int i = 1; i < size; i++)
    {
        int pick = Houses[i] + second_prev;
        int notpick = 0 + prev;
        second_prev = prev;
        prev = max(pick, notpick);
    }
    return prev;
}

int main()
{
    int size = 0;
    cin >> size;
    vector<int> v(size);
    vector<int> dp(size, -1);
    for (int i = 0; i < size; i++)
    {
        cin >> v[i];
    }
    cout << Maximum_Sum_of_Non_Adjacent_Memo(v, size - 1, dp) << "\n";
    cout << Maximum_Sum_of_Non_Adjacent_Tabulation(v) << "\n";
    cout << Maximum_Sum_of_Non_Adjacent_Space_Optimisation(v);
}
