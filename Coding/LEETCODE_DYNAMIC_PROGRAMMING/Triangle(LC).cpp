// LEETCODE: 120. Triangle (dp, memoization ,tabulation)

//MEMOIZATION
class Solution {
public:
   int min_path_triangle(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp,int n)
   {  if(i==n-1) return triangle[n-1][j];

      if(dp[i][j]!=-1) return dp[i][j];

      int down=triangle[i][j]+min_path_triangle(i+1,j,triangle,dp,n);
      int diagonal=triangle[i][j]+min_path_triangle(i+1,j+1,triangle,dp,n);
      return dp[i][j]=min(down,diagonal);
   }
    int minimumTotal(vector<vector<int>>& triangle) {
       int n=triangle.size();
       vector<vector<int>>dp(n,vector<int>(n,-1));
       return  min_path_triangle(0,0,triangle,dp,n);
        
    }
};
// Time Complexity: (n(n+1))/2 => o(n^2) (approx)
// Space Complexity:O(n²) + O(n) = O(n²)

//TABULATION

class Solution {
public:
   int min_path_triangle(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp,int n)
   {  if(i==n-1) return triangle[n-1][j];

      if(dp[i][j]!=-1) return dp[i][j];

      int down=triangle[i][j]+min_path_triangle(i+1,j,triangle,dp,n);
      int diagonal=triangle[i][j]+min_path_triangle(i+1,j+1,triangle,dp,n);
      return dp[i][j]=min(down,diagonal);
   }
    int minimumTotal(vector<vector<int>>& triangle) {
       int n=triangle.size();
       vector<vector<int>>dp(n,vector<int>(n,-1));
      for(int i=0;i<n;i++)
      {
        dp[n-1][i]=triangle[n-1][i];
      }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int down=triangle[i][j]+dp[i+1][j];
                int diagonal=triangle[i][j]+dp[i+1][j+1];
                 dp[i][j]=min(down,diagonal);
            }
        }
        return dp[0][0];
    }
};
//Time Complexity: (n(n+1))/2 => o(n^2) (approx)
// Space Complexity:O(n²)
