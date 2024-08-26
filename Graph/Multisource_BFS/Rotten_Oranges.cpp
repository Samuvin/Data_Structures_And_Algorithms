class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res=0;
        queue<pair<int,int>>level;
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        bool isRotten=false;
        int fresh=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    isRotten=true;
                    vis[i][j]=1;
                    level.push({i,j});
                }
                if(grid[i][j]==1)
                    fresh++;
            }
        }
        int x[]={0,0,1,-1};
        int y[]={1,-1,0,0};
        
        while(!level.empty())
        {
            int size=level.size();
            for(int i=0;i<size;i++)
            {
                int dx=level.front().first;
                int dy=level.front().second;
                level.pop();
                for(int i=0;i<4;i++)
                {
                    int nx=dx+x[i];
                    int ny=dy+y[i];
                    if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size() && !vis[nx][ny] && grid[nx][ny]==1)
                    {
                        fresh--;
                        level.push({nx,ny});
                        vis[nx][ny]=1;
                    }
                }
            }
            res++;
        }
        if(fresh!=0)
            return -1;
        return isRotten?res-1:0;
    }
};
