// LEETCODE:64. Minimum Path Sum (DP,MEMOIZATION,TABULATION)

//MEMOIZATION

class Solution {
public:
    int minpathgrid(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        if(i==0 && j==0) return grid[i][j];
        if(i<0 || j<0)  return 1e9; 
        if(dp[i][j]!=-1) return dp[i][j];

        int up=grid[i][j]+minpathgrid(i-1,j,grid,dp);
        int left=grid[i][j]+minpathgrid(i,j-1,grid,dp);

        return dp[i][j]=min(left,up);

    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        return minpathgrid(n-1,m-1,grid,dp);
    }
};
// TIME COMPLEXITY: O(N*M)
// SPACE Complexity: = O(m * n) (for dp) + O(m + n) (for recursion stack)
// But we usually consider the dominating term: O(m * n).


// TABULATION

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0) dp[i][j]=grid[i][j];
                else if(i<0 || j<0) dp[i][j]=1e9; // can remove this condition since in loop i and j never be negative

                else{
                    int up=(i>0)?grid[i][j]+dp[i-1][j]:1e9;
                    int left=(j>0)?grid[i][j]+dp[i][j-1]:1e9;

                    dp[i][j]=min(up,left);
                }
            }
        }
        return dp[n-1][m-1];       
    }
};
// TIME COMPLEXITY: O(N*M)
// SPACE COMPLEXITY:O(N*M)
