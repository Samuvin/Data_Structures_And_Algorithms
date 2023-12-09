#include <iostream>
#include <vector>
using namespace std;

int LCS_Recursion(string &str1, string &str2, int ind1, int ind2, int &maxi)
{
    if (ind1 < 0 || ind2 < 0)
        return 0;
    int len = 0;
    if (str1[ind1] == str2[ind2])
    {
        len = 1 + LCS_Recursion(str1, str2, ind1 - 1, ind2 - 1, maxi);
    }
    maxi = max(maxi, len);
    LCS_Recursion(str1, str2, ind1 - 1, ind2, maxi);
    LCS_Recursion(str1, str2, ind1, ind2 - 1, maxi);
    return len;
}
int LCS_Memo(string &str1, string &str2, int ind1, int ind2, vector<vector<int>> &dp, int &maxi)
{
    if (ind1 < 0 || ind2 < 0)
    {
        return 0;
    }
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    int len = 0;
    if (str1[ind1] == str2[ind2])
    {
        len = 1 + LCS_Memo(str1, str2, ind1 - 1, ind2 - 1, dp, maxi);
    }
    maxi = max(maxi, len);
    LCS_Memo(str1, str2, ind1 - 1, ind2, dp, maxi);
    LCS_Memo(str1, str2, ind1, ind2 - 1, dp, maxi);
    return dp[ind1][ind2] = len;
}

int LCS_Tabulation(string &str1, string &str2)
{
    int size1 = str1.size();
    int size2 = str2.size();
    int maxi = 0;
    vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));
    for (int i = 1; i <= size1; i++)
    {
        for (int j = 1; j <= size2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            maxi = max(dp[i][j], maxi);
        }
    }
    return maxi;
}

int LCS_Space_Optimisation(string &str1, string &str2)
{
    vector<int> dp(str2.size() + 1, 0), curr(str2.size() + 1, 0);
    int maxi = 0;
    for (int i = 1; i <= str1.size(); i++)
    {
        for (int j = 1; j <= str2.size(); j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                curr[j] = 1 + dp[j - 1];
            }
            else
            {
                curr[j] = 0;
            }
            maxi = max(maxi, curr[j]);
        }
        dp = curr;
    }
    return maxi;
}
int LCS_Space_Optimisation_2(string &str1, string &str2)
{
    vector<int> dp(str2.size() + 1, 0);
    int curr = 0;
    int maxi = 0;
    for (int i = 1; i <= str1.size(); i++)
    {
        for (int j = str2.size(); j >= 1; j--)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                curr = 1 + dp[j - 1];
            }
            else
            {
                curr = 0;
            }
            maxi = max(maxi, curr);
            dp[j] = curr;
        }
    }
    return maxi;
}
int lcs(string &str1, string &str2)
{
    int maxi1 = 0;
    int maxi2 = 0;
    vector<vector<int>> dp(str1.size(), vector<int>(str2.size(), -1));
    cout << LCS_Space_Optimisation_2(str1, str2) << "\n";
    cout << LCS_Space_Optimisation(str1, str2) << "\n";
    cout << LCS_Tabulation(str1, str2) << "\n";
    LCS_Memo(str1, str2, str1.size() - 1, str2.size() - 1, dp, maxi1);
    cout << maxi1 << "\n";
    LCS_Recursion(str1, str2, str1.size() - 1, str2.size() - 1, maxi2);
    cout << maxi2 << "\n";
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    lcs(str1, str2);
}
