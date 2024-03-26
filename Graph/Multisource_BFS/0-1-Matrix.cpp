class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> result(n, vector<int>(m, 0));
        queue<pair<int, int>> vertex;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (mat[row][col] == 0)
                {
                    vertex.push({row, col});
                    visited[row][col] = 1;
                }
            }
        }
        int distance = 0;
        int x_axis[] = {1, -1, 0, 0};
        int y_axis[] = {0, 0, 1, -1};
        while (!vertex.empty())
        {
            int Curr_Level_Length = vertex.size();
            for (int level = 0; level < Curr_Level_Length; level++)
            {
                int row = vertex.front().first;
                int col = vertex.front().second;
                vertex.pop();
                result[row][col] = distance;
                for (int j = 0; j < 4; j++)
                {
                    int nrow = row + x_axis[j];
                    int ncol = col + y_axis[j];
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol])
                    {
                        vertex.push({nrow, ncol});
                        visited[nrow][ncol] = 1;
                    }
                }
            }
            distance++;
        }
        return result;
    }
};
