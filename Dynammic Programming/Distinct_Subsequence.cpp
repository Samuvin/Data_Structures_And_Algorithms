#include <iostream>
#include <vector>
using namespace std;
int Distinct_Subsequence_Recursive(string s, string t, int ind1, int ind2)
{
    if (ind2 < 0)
        return 1;
    if (ind1 < 0)
        return 0;
    int pick = 0;
    if (s[ind1] == t[ind2])
    {
        return Distinct_Subsequence_Recursive(s, t, ind1 - 1, ind2 - 1) + Distinct_Subsequence_Recursive(s, t, ind1 - 1, ind2);
    }
    return Distinct_Subsequence_Recursive(s, t, ind1 - 1, ind2);
}
int Distinct_Subsequence_Memo(string s, string t, int ind1, int ind2, vector<vector<int>> &dp)
{
    if (ind2 < 0)
        return 1;
    if (ind1 < 0)
        return 0;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    if (s[ind1] == t[ind2])
    {
        return dp[ind1][ind2] = Distinct_Subsequence_Memo(s, t, ind1 - 1, ind2 - 1, dp) + Distinct_Subsequence_Memo(s, t, ind1 - 1, ind2, dp);
    }
    return dp[ind1][ind2] = Distinct_Subsequence_Memo(s, t, ind1 - 1, ind2, dp);
}
int Distinct_Subsequence_Memo_Helper(string &s, string &t)
{
    vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
    return Distinct_Subsequence_Memo(s, t, s.size() - 1, t.size() - 1, dp);
}
int Distinct_Subsequence_Tabulation(string &s, string &t)
{
    int mod = 1e9 + 7;
    int s_size = s.size();
    int t_size = t.size();
    vector<vector<int>> dp(s_size + 1, vector<int>(t_size + 1, 0));
    for (int i = 0; i <= s_size; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= s_size; i++)
    {
        for (int j = 1; j <= t_size; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[s_size][t_size];
}
int Distinct_Subsequence_Space_Optimisation(string &s, string &t)
{
    int mod = 1e9 + 7;
    int s_size = s.size();
    int t_size = t.size();
    vector<int> dp(t_size + 1, 0), curr(t_size + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= s_size; i++)
    {
        curr[0] = 1;
        for (int j = 1; j <= t_size; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                curr[j] = (dp[j - 1] + dp[j]) % mod;
            }
            else
            {
                curr[j] = dp[j];
            }
        }
        dp = curr;
    }
    return dp[t_size];
}
int Distinct_Subsequence_Space_Optimisation_2(string &s, string &t)
{
    int mod = 1e9 + 7;
    int s_size = s.size();
    int t_size = t.size();
    vector<int> dp(t_size + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= s_size; i++)
    {
        for (int j = t_size; j >= 1; j--)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[j] = (dp[j] + dp[j - 1]) % mod;
            }
        }
    }
    return dp[t_size];
}
void Count_Distinct(string s, string t)
{
    int s_size = s.size();
    int t_size = t.size();
    cout << Distinct_Subsequence_Space_Optimisation_2(s, t) << "\n";
    cout << Distinct_Subsequence_Space_Optimisation(s, t) << "\n";
    cout << Distinct_Subsequence_Tabulation(s, t) << "\n";
    cout << Distinct_Subsequence_Memo_Helper(s, t) << "\n";
    cout << Distinct_Subsequence_Recursive(s, t, s_size - 1, t_size - 1) << "\n";
}
int main()
{
    string s, t;
    cin >> s >> t;
    Count_Distinct(s, t);
}
