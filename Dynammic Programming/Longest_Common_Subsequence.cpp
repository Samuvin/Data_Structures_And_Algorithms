#include <iostream>
#include <vector>
using namespace std;
int LongestCommonSubsequence_Recursive(string text1, string text2, int ind1, int ind2)
{
    if (ind1 < 0 || ind2 < 0)
    {
        return 0;
    }
    if (text1[ind1] == text2[ind2])
    {
        return 1 + LongestCommonSubsequence_Recursive(text1, text2, ind1 - 1, ind2 - 1);
    }
    int skip_str1 = 0 + LongestCommonSubsequence_Recursive(text1, text2, ind1 - 1, ind2);
    int skip_str2 = 0 + LongestCommonSubsequence_Recursive(text1, text2, ind1, ind2 - 1);
    return max(skip_str1, skip_str2);
}
int LongestCommonSubsequence_Memo(string text1, string text2, int ind1, int ind2, vector<vector<int>> &dp)
{
    if (ind1 < 0 || ind2 < 0)
    {
        return 0;
    }
    if (dp[ind1][ind2] != -1)
    {
        return dp[ind1][ind2];
    }
    if (text1[ind1] == text2[ind2])
    {
        return 1 + LongestCommonSubsequence_Memo(text1, text2, ind1 - 1, ind2 - 1, dp);
    }
    int skip_str1 = LongestCommonSubsequence_Memo(text1, text2, ind1 - 1, ind2, dp);
    int skip_str2 = LongestCommonSubsequence_Memo(text1, text2, ind1, ind2 - 1, dp);
    return dp[ind1][ind2] = max(skip_str1, skip_str2);
}
int LongestCommonSubsequence_Tabulation(string &text1, string &text2)
{
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    for (int i = 1; i <= text1.size(); i++)
    {
        for (int j = 1; j <= text2.size(); j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[text1.size()][text2.size()];
}
int LongestCommonSubsequence_Space_Optimisation(string &text1, string &text2)
{
    int size1 = text1.size();
    int size2 = text2.size();
    vector<int> dp(size2 + 1, 0), curr_row(size2 + 1, 0);
    for (int i = 1; i <= size1; i++)
    {
        for (int j = 1; j <= size2; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                curr_row[j] = 1 + dp[j - 1];
            }
            else
            {
                curr_row[j] = max(dp[j], curr_row[j - 1]);
            }
        }
        dp = curr_row;
    }
    return dp[size2];
}
int longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
    cout << LongestCommonSubsequence_Space_Optimisation(text1, text2) << '\n';
    cout << LongestCommonSubsequence_Tabulation(text1, text2) << "\n";
    cout << LongestCommonSubsequence_Memo(text1, text2, text1.size() - 1, text2.size() - 1, dp) << "\n";
    cout << LongestCommonSubsequence_Recursive(text1, text2, text1.size() - 1, text2.size() - 1) << "\n";
}
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    longestCommonSubsequence(str1, str2);
}
