// GFG: Number of Distinct Islands (DFS)

// ANALYSE THE BELOW APPROACH AND UTILIZE IN THE PROBLEM CALLED NUMBER OF ISLANDS IN LEETCODE

class Solution {
  public:
    void dfs(int row,int col,vector<pair<int,int>>& ans,vector<vector<int>>& vis,vector<vector<int>>& grid,int drow[] ,int dcol[] ,int row_0,int col_0,int n,int m)
    {
        vis[row][col]=1;
        ans.push_back({row_0-row,col_0-col});
        
        for(int i=0;i<4;i++)
        {
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1)
            {
                dfs(nrow,ncol,ans,vis,grid,drow,dcol,row_0,col_0,n,m);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>st;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {   vector<pair<int,int>> ans;
                if(!vis[i][j] && grid[i][j]==1)
                {
                    dfs(i,j,ans,vis,grid,drow,dcol,i,j,n,m);
                    st.insert(ans);
                }
            }
        }
        return st.size();
        
    }
};

//TIME COMPLEXITY:  O(n * m * log k) -> on average and in the worst case, inserting into a C++ std::set takes O(log k) time,
//where k is the number of elements currently in the set(UNIQUE ELEMENTS).

//SPACE COMPLEXITY:	O(n * m)
