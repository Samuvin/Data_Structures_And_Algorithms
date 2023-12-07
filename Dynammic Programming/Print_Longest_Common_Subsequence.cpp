#include <iostream>
#include <vector>
using namespace std;

string Print_LCS_Recursive(string s1, string s2, int ind1, int ind2)
{
    if (ind1 == s1.size() || ind2 == s2.size())
        return "";
    if (s1[ind1] == s2[ind2])
    {
        return s1[ind1] + Print_LCS_Recursive(s1, s2, ind1 + 1, ind2 + 1);
    }
    string str1 = Print_LCS_Recursive(s1, s2, ind1, ind2 + 1);
    string str2 = Print_LCS_Recursive(s1, s2, ind1 + 1, ind2);
    return str1.size() > str2.size() ? str1 : str2;
}
string Print_LCS_Memoisze(string s1, string s2, int ind1, int ind2, vector<vector<string>> &dp)
{
    if (ind1 == s1.size() || ind2 == s2.size())
        return "";
    if (dp[ind1][ind2] != "$")
        return dp[ind1][ind2];
    if (s1[ind1] == s2[ind2])
        return s1[ind1] + Print_LCS_Memoisze(s1, s2, ind1 + 1, ind2 + 1, dp);
    string str1 = Print_LCS_Memoisze(s1, s2, ind1 + 1, ind2, dp);
    string str2 = Print_LCS_Memoisze(s1, s2, ind1, ind2 + 1, dp);
    return (dp[ind1][ind2] = str1.size() > str2.size() ? str1 : str2);
}
string Print_LCS_Tabulation(string s1, string s2)
{
    int str1_size = s1.size();
    int str2_size = s2.size();
    vector<vector<int>> dp(str1_size + 1, vector<int>(str2_size + 1, 0));
    for (int i = 1; i <= str1_size; i++)
    {
        for (int j = 1; j <= str2_size; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int LCS_LEN = dp[str1_size][str2_size];
    int i = str1_size, j = str2_size;
    string res(LCS_LEN, '&');
    int ind = LCS_LEN - 1;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            res[ind] = s1[i - 1];
            ind--;
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                i = i - 1;
            }
            else
            {
                j = j - 1;
            }
        }
    }
    return res;
}
string findLCS(string &s1, string &s2)
{
    vector<vector<string>> dp(s1.size(), vector<string>(s2.size(), "$"));
    cout << Print_LCS_Memoisze(s1, s2, 0, 0, dp) << "\n";
    cout << Print_LCS_Recursive(s1, s2, 0, 0) << '\n';
    cout << Print_LCS_Tabulation(s1, s2) << "\n";
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    findLCS(str1, str2);
}
