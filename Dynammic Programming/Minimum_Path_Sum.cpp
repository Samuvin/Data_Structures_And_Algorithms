#include <iostream>
#include <vector>
using namespace std;

int Minimum_Path_Sum(vector<vector<int>> &grid, int row, int col)
{
    if (row == 0 && col == 0)
    {
        return grid[0][0];
    }
    if (row < 0 || col < 0)
    {
        return 1e9;
    }
    int up = grid[row][col] + Minimum_Path_Sum(grid, row - 1, col);
    int left = grid[row][col] + Minimum_Path_Sum(grid, row, col - 1);
    return min(left, up);
}

int Minimum_Path_Sum_Memo(vector<vector<int>> &grid, vector<vector<int>> &dp, int row, int col)
{
    if (row == 0 && col == 0)
    {
        return grid[0][0];
    }
    if (row < 0 || col < 0)
    {
        return 1e9;
    }
    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }
    long long up = grid[row][col] + Minimum_Path_Sum_Memo(grid, dp, row - 1, col);
    long long left = grid[row][col] + Minimum_Path_Sum_Memo(grid, dp, row, col - 1);
    return dp[row][col] = min(left, up);
}

int Minimum_Path_Sum_Tabulation(vector<vector<int>> &grid, int row, int col)
{
    vector<vector<int>> dp(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == 0 && j == 0)
                dp[0][0] = grid[0][0];
            else
            {
                int up = 0;
                int left = 0;
                if (i > 0)
                {
                    up = grid[i][j] + dp[i - 1][j];
                }
                else
                {
                    up = 1e9;
                }
                if (j > 0)
                {
                    left = grid[i][j] + dp[i][j - 1];
                }
                else
                {
                    left = 1e9;
                }
                dp[i][j] = min(left, up);
            }
        }
    }
    return dp[row - 1][col - 1];
}

int Minimum_Path_Sum_Space_Optimization(vector<vector<int>> Grid, int row, int col)
{
    vector<int> dp(Grid[0].size(), 0);
    for (int i = 0; i < row; i++)
    {
        vector<int> curr(Grid[0].size(), 0);
        for (int j = 0; j < col; j++)
        {
            if (i == 0 && j == 0)
            {
                curr[j] = Grid[0][0];
            }
            else
            {
                int up = Grid[i][j];
                int left = Grid[i][j];
                if (i > 0)
                {
                    up += dp[j];
                }
                else
                {
                    up += 1e9;
                }
                if (j > 0)
                {
                    left += curr[j - 1];
                }
                else
                {
                    left += 1e9;
                }
                curr[j] = min(left, up);
            }
        }
        dp = curr;
    }
    return dp[col - 1];
}

void Dynammic_Programming(vector<vector<int>> &Grid, int row, int col)
{
    vector<vector<int>> dp(row, vector<int>(col, -1));
    cout << "Recursion  : " << Minimum_Path_Sum(Grid, row - 1, col - 1) << "\n";
    cout << "Memoization : " << Minimum_Path_Sum_Memo(Grid, dp, row - 1, col - 1) << "\n";
    cout << "Tabulation  : " << Minimum_Path_Sum_Tabulation(Grid, row, col) << "\n";
    cout << "Space Optimization : " << Minimum_Path_Sum_Space_Optimization(Grid, row, col) << "\n";
}

int main()
{
    int row, col;
    cin >> row >> col;
    vector<vector<int>> Grid(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> Grid[i][j];
        }
    }
    Dynammic_Programming(Grid, row, col);
}
