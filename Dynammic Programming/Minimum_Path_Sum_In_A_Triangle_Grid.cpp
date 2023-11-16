#include <iostream>
#include <vector>
using namespace std;
int Triangular_Grid_Recursion(vector<vector<int>> &triangle, int row, int col, int level)
{
    if (level - 1 == row)
        return triangle[row][col];
    int down = triangle[row][col] + Triangular_Grid_Recursion(triangle, row + 1, col, level);
    int right = triangle[row][col] + Triangular_Grid_Recursion(triangle, row + 1, col + 1, level);
    return min(down, right);
}
int Triangular_Grid_Memo(vector<vector<int>> &triangle, int row, int col, int level, vector<vector<int>> &dp)
{
    if (level - 1 == row)
        return triangle[row][col];
    if (dp[row][col] != -1)
        return dp[row][col];
    int down = triangle[row][col] + Triangular_Grid_Memo(triangle, row + 1, col, level, dp);
    int right = triangle[row][col] + Triangular_Grid_Memo(triangle, row + 1, col + 1, level, dp);
    return dp[row][col] = min(down, right);
}
int Triangular_Grid_Tabulation(vector<vector<int>> &triangle, int level)
{
    vector<vector<int>> dp(level, vector<int>(level, 0));
    for (int i = 0; i < level; i++)
        dp[level - 1][i] = triangle[level - 1][i];
    for (int row = level - 2; row >= 0; row--)
    {
        for (int col = 0; col <= row; col++)
        {
            int down = triangle[row][col] + dp[row + 1][col];
            int left = triangle[row][col] + dp[row + 1][col + 1];
            dp[row][col] = min(left, down);
        }
    }
    return dp[0][0];
}
int Triangular_Grid_Space_Optimization(vector<vector<int>> &triangle, int level)
{
    vector<int> dp(level, 0);
    for (int i = 0; i < level; i++)
    {
        dp[i] = triangle[level - 1][i];
    }
    for (int row = level - 2; row >= 0; row--)
    {
        vector<int> temp(row + 1, 0);
        for (int col = 0; col <= row; col++)
        {
            int up = triangle[row][col] + dp[col];
            int left = triangle[row][col] + dp[col + 1];
            temp[col] = min(left, up);
        }
        dp = temp;
    }
    return dp[0];
}
void minimumTotal(vector<vector<int>> &triangle)
{
    int level = triangle.size();
    vector<vector<int>> dp(level, vector<int>(level, -1));
    cout<<Triangular_Grid_Space_Optimization(triangle, level)<<"\n";
    cout<<Triangular_Grid_Tabulation(triangle, level)<<"\n";
    cout<<Triangular_Grid_Memo(triangle, 0, 0, level, dp)<<"\n";
    cout<<Triangular_Grid_Recursion(triangle, 0, 0, level)<<"\n";
}
int main()
{
    int size;
    cin>>size;
    vector<vector<int>> triangle(size,vector<int>(size,0));
    for(int row=0;row<size;row++)
    {
        for(int col=0;col<=row;col++)
        {
            cin>>triangle[row][col];
        }
    }
    minimumTotal(triangle);
}
