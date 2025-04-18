// LEETCODE: 542. 01 Matrix (BFS)

// just same problem as Distance of nearest cell having 1 ,but in 01 matrix we find nearest cell having 0

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> distance(n,vector<int>(m,1));
        vector<vector<int>> vis(n,vector<int>(m,1));
        queue<pair<pair<int,int>,int>>qu;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    vis[i][j]=0;
                    qu.push({{i,j},0});
                }
            }
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        while(!qu.empty())
        {
            int row=qu.front().first.first;
            int col=qu.front().first.second;
            int steps=qu.front().second;
            qu.pop();
            
            distance[row][col]=steps;
            for(int i=0;i<4;i++)
            {
            int nrow=row+drow[i];
            int ncol=col+dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==1)
            {
                vis[nrow][ncol]=0;
                qu.push({{nrow,ncol},steps+1});
            }
            }

        }
        return distance;

        
    }
};

// Time Complexity: O(n * m)
// Space Complexity: O(n * m)
