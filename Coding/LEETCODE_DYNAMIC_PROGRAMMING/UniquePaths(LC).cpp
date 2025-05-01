// LEETCODE: 62. Unique Paths ( DP,MEMOIZATION,TABULATION)
//NOTE: DO THIS PROBLEM USING SPACE OPTIMIZATION APPROACH
class Solution {
public:
    int allpossiblepaths(int i,int j,vector<vector<int>>&dp)
    {
        if(i==0 || j==0) return 1; // can use if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int up=allpossiblepaths(i-1,j,dp);
        int left=allpossiblepaths(i,j-1,dp);
         
         return dp[i][j]=up+left;
      
    }
    int uniquePaths(int m, int n) {
       vector<vector<int>> dp(m,vector<int>(n,-1));
        return allpossiblepaths(m-1,n-1,dp);
        
    }
};
//  Time Complexity: O(m * n)
//  Space Complexity: = O(m * n) (for dp) + O(m + n) (for recursion stack)
// But we usually consider the dominating term: O(m * n).

//TABULATION
class Solution {
public:
    
    int uniquePaths(int m, int n) {
       vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0) dp[i][j]=1;
                else{
                     int up = (i > 0) ? dp[i-1][j] : 0;
                    int left = (j > 0) ? dp[i][j-1] : 0;
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[m-1][n-1];
        
    }
};
// Time Complexity: O(m * n)
// Space Complexity: O(m * n) // NO STACK SPACE
