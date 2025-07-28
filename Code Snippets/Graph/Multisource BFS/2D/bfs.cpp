#include <bits/stdc++.h>
using namespace std;

bool isPathValid(int row, int col, int n, int m, vector<string> &grid, vector<vector<int>> &dist, int nextRow, int nextCol)
{
    return row >= 0 && row < n && col >= 0 && col < m && grid[row][col] != '#' && dist[row][col] + 1 < dist[nextRow][nextCol];
}

void multiSourceBfs(queue<pair<int, int>> &q, vector<vector<int>> &dist, vector<vector<int>> &direction, vector<string> &grid, vector<int> &dirR, vector<int> &dirC)
{
    int n = grid.size();
    int m = grid[0].size();
    while (!q.empty())
    {
        int nodeRow = q.front().first;
        int nodeCol = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d++)
        {
            int nextrow = nodeRow + dirR[d], nextcol = nodeCol + dirC[d];
            if (isPathValid(nextrow, nextcol, n, m, grid, dist, nextrow, nextcol))
            {
                dist[nextrow][nextcol] = dist[nodeRow][nodeCol] + 1;
                direction[nextrow][nextcol] = d;
                q.push({nextrow, nextcol});
            }
        }
    }
}
