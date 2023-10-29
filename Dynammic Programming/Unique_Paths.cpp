#include <iostream>
#include <vector>
using namespace std;
long long Unique_Path_In_A_Grid_Memo(int row, int col, vector<vector<int>> &dp)
{
    if (row == 0 && col == 0)
    {
        return 1;
    }
    if (row < 0 || col < 0)
    {
        return 0;
    }
    if (dp[row][col] != -1)
        return dp[row][col];
    int up = Unique_Path_In_A_Grid_Memo(row - 1, col, dp);
    int left = Unique_Path_In_A_Grid_Memo(row, col - 1, dp);
    return dp[row][col] = left + up;
}
long long Unique_Path_In_A_Grid_Tabulation(int row, int col)
{
    vector<vector<int>> dp(row, vector<int>(col, 0));
    dp[0][0] = 1;
    for (int ro = 0; ro < row; ro++)
    {
        for (int column = 0; column < col; column++)
        {
            int up = 0;
            int left = 0;
            if (ro - 1 >= 0)
            {
                dp[ro][column] += dp[ro - 1][column];
            }
            if (column - 1 >= 0)
            {
                dp[ro][column] += dp[ro][column - 1];
            }
        }
    }
    return dp[row - 1][col - 1];
}
long long Space_Optimization(int row, int col)
{
    vector<int> dp(col, 0);
    dp[0] = 1;
    for (int r = 0; r < row; r++)
    {
        vector<int> temp(col, 0);
        for (int c = 0; c < col; c++)
        {
            int up = 0;
            int left = 0;
            temp[c] += dp[c];
            if (c - 1 >= 0)
            {
                temp[c] += temp[c - 1];
            }
        }
        dp = temp;
    }
    return dp[col - 1];
}
int main()
{
    int row, col;
    cin >> row >> col;
    vector<vector<int>> dp(row, vector<int>(col, -1));
    cout << Unique_Path_In_A_Grid_Memo(row - 1, col - 1, dp) << "\n";
    cout << Unique_Path_In_A_Grid_Tabulation(row, col) << "\n";
    cout << Space_Optimization(row, col) << "\n";
}
