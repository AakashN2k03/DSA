// LEETCODE: 200. Number of Islands ( BFS , QUEUE ) 

// NOTE : THIS FOLLOWS NEIGHBOURHOOD OF FOUR DIRECTIONS ALONE

class Solution {
public:
    void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        queue<pair<int,int>> qu; // ROW , COL
         qu.push({row,col});
         int neighbour_row_Arr[]={-1,0,1,0}; // [UP,RIGHT,DOWN,LEFT]
         int neighbour_col_Arr[]={0,-1,0,1};

         while(!qu.empty())
         {
            int row=qu.front().first;
            int col=qu.front().second;
            qu.pop();

            for(int i=0;i<4;i++)
            {
                    int neighbour_row=row+neighbour_row_Arr[i];
                    int neighbour_col= col+neighbour_col_Arr[i];
                    if(neighbour_row>=0 && neighbour_row<n && neighbour_col>=0 && neighbour_col<m &&
                    grid[neighbour_row][neighbour_col]=='1' && !vis[neighbour_row][neighbour_col])
                    {
                        vis[neighbour_row][neighbour_col]=1;
                        qu.push({neighbour_row,neighbour_col});
                    }
                
            }
         }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int counter=0;
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(!vis[row][col] && grid[row][col]=='1')
                {   counter++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return counter;
        
    }
};
// ✅ Time Complexity: O(n × m)
// ✅ Space Complexity:
// visited array: O(n × m)

// queue (in worst case): O(n × m) if the entire grid is one big island.
// So, space complexity is also:O(n × m)


// use the below shortcut to find 8 directions
          // for(int allrow=-1;allrow<=1;allrow++)
          //   {
          //       for(int allcol=-1;allcol<=1;allcol++)
          //       {
          //           int neighbour_row=row+allrow;
          //           int neighbour_col= col+allcol;
          //           if(allrow>=0 && allrow<n && allcol>=0 && allcol<m &&
          //           grid[neighbour_row][neighbour_col]=='1' && !vis[neighbour_row][neighbour_col])
          //           {
          //               vis[neighbour_row][neighbour_col]=1;
          //               qu.push({neighbour_row,neighbour_col});
          //           }
          //       }
            // }
