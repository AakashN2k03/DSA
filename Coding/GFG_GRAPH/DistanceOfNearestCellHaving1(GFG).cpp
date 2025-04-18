// GFG: Distance of nearest cell having 1 ( BFS )

class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> distance(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> qu; // ROW , COL , STEPS 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    vis[i][j]=1;
                    qu.push({{i,j},0});
                }
            }
        }
        
        int drow []={-1,0,1,0};
        int dcol []={0,1,0,-1};
        
        while(!qu.empty())
        {
            int row=qu.front().first.first;
            int col=qu.front().first.second;
            int steps=qu.front().second;
            distance[row][col]=steps;
            qu.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0)
                {
                    vis[nrow][ncol]=1;
                    qu.push({{nrow,ncol},steps+1});
                }
            }
        }
        return distance;
    }
};

// Time Complexity: O(n * m)
// Space Complexity: O(n * m)
