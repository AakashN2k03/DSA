// LEETCODE: 1020. Number of Enclaves ( BFS )

// STEPS
// 1. FIND THE ONES IN THE BOUNDARY.
// 2. ALSO FIND THE ONES CONNECTED WITH THE BOUNDARY ONES.
// 3. ATLAST COUNT THE REMAINING ONES , NOT CONNECTED WITH THE BOUNDARY ONES.

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>> qu;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)   //checking whether a cell is on the boundary of the grid.
                {
                    if(grid[i][j]==1)
                    {
                        vis[i][j]=1;
                        qu.push({i,j});
                    }
                }
            }
        }

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!qu.empty())
        {
          int row=qu.front().first;
          int col=qu.front().second;
          qu.pop();

          for(int i=0;i<4;i++)
          {
            int nrow=row+drow[i];
            int ncol=col+dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1)
            {
                vis[nrow][ncol]=1;
                qu.push({nrow,ncol});
            }

          }

        }

        int counter=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    counter++;
                }
            }
        }
        return counter;
        
    }
};

// Time Complexity: O(N * M)
// Space Complexity: O(N * M)
