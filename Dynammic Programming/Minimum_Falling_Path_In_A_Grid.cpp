#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int Falling_Path_Sum__Recursion(vector<vector<int>> &matrix, int row, int col)
{
    if (col < 0 || col >= matrix[0].size())
        return 1e9;
    if (row == 0)
        return matrix[row][col];
    int up = matrix[row][col] + Falling_Path_Sum__Recursion(matrix, row - 1, col);
    int left = matrix[row][col] + Falling_Path_Sum__Recursion(matrix, row - 1, col - 1);
    int right = matrix[row][col] + Falling_Path_Sum__Recursion(matrix, row - 1, col + 1);
    return min({up, left, right});
}
int Falling_Path_Sum_Memo(vector<vector<int>> &matrix, int row, int col, vector<vector<int>> &dp)
{
    if (col < 0 || col >= matrix[0].size())
        return 1e9;
    if (row == 0)
        return matrix[row][col];
    if (dp[row][col] != -1)
        return dp[row][col];
    int up = matrix[row][col] + Falling_Path_Sum_Memo(matrix, row - 1, col, dp);
    int left = matrix[row][col] + Falling_Path_Sum_Memo(matrix, row - 1, col - 1, dp);
    int right = matrix[row][col] + Falling_Path_Sum_Memo(matrix, row - 1, col + 1, dp);
    return dp[row][col] = min({up, left, right});
}
int Falling_Path_Sum_Tabulation(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> dp(row, vector<int>(col, -1));
    for (int i = 0; i < col; i++)
    {
        dp[0][i] = matrix[0][i];
    }
    for (int r = 1; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            int up = matrix[r][c] + dp[r - 1][c];
            int left = matrix[r][c] + (c - 1 >= 0 ? dp[r - 1][c - 1] : 1e9);
            int right = matrix[r][c] + (c + 1 < col ? dp[r - 1][c + 1] : 1e9);
            dp[r][c] = min({up, left, right});
        }
    }
    int mini = INT_MAX;
    for (int i = 0; i < col; i++)
    {
        mini = min(mini, dp[row - 1][i]);
    }
    return mini;
}
int Falling_Path_Sum_Space_Optimization(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> dp(col, 0);
    for (int i = 0; i < col; i++)
    {
        dp[i] = matrix[0][i];
    }
    for (int r = 1; r < row; r++)
    {
        vector<int> curr(col, 0);
        for (int c = 0; c < col; c++)
        {
            int up = matrix[r][c] + dp[c];
            int right = matrix[r][c] + (c - 1 >= 0 ? dp[c - 1] : 1e9);
            int left = matrix[r][c] + (c + 1 < col ? dp[c + 1] : 1e9);
            curr[c] = min({up, left, right});
        }
        dp = curr;
    }
    int mini = INT_MAX;
    for (int i = 0; i < col; i++)
    {
        mini = min(mini, dp[i]);
    }
    return mini;
}
int Solve(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> dp(row, vector<int>(col, -1));
    int mini = INT_MAX;
    for (int i = 0; i < col; i++)
    {
        int path = Falling_Path_Sum_Memo(matrix, row - 1, i, dp);
        mini = min(mini, path);
    }
    return mini;
}
void MinFallingPathSum(vector<vector<int>> &matrix)
{
    cout << Solve(matrix) << "\n";
    cout << Falling_Path_Sum_Tabulation(matrix) << "\n";
    cout << Falling_Path_Sum_Space_Optimization(matrix) << "\n";
}
int main()
{
    int row, col;
    cin >> row >> col;
    vector<vector<int>> Grid(row, vector<int>(col));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> Grid[i][j];
        }
    }
    MinFallingPathSum(Grid);
}
