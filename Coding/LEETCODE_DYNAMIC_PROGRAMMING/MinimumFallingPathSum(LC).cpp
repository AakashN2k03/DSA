// LEETCODE: 931. Minimum Falling Path Sum (DP,MEMOIZATION ,TABULATION)

class Solution {
public:
    int min_path_sum(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp)
    {
        if(j<0 || j>=matrix[0].size()) return 1e9;
        if(i==0) return matrix[0][j];

        if(dp[i][j]!=-1) return dp[i][j];
        int up=matrix[i][j]+min_path_sum(i-1,j,matrix,dp);
        int left_diagonal=matrix[i][j]+min_path_sum(i-1,j-1,matrix,dp);
        int right_diagonal=matrix[i][j]+min_path_sum(i-1,j+1,matrix,dp);
        return dp[i][j]=min({up,left_diagonal,right_diagonal});

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        int mini=1e9;
       for(int j=0;j<m;j++)
       {
        mini=min(mini,min_path_sum(n-1,j,matrix,dp));
       }
       return mini;
        
    }
};

// Time Complexity:O(n × m) + O(n)  (for mini loop)
// Space Complexity:O(n × m) + O(n)

// TABULATION
class Solution {
public:
    int min_path_sum(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp)
    {
        if(j<0 || j>=matrix[0].size()) return 1e9;
        if(i==0) return matrix[0][j];

        if(dp[i][j]!=-1) return dp[i][j];
        int up=matrix[i][j]+min_path_sum(i-1,j,matrix,dp);
        int left_diagonal=matrix[i][j]+min_path_sum(i-1,j-1,matrix,dp);
        int right_diagonal=matrix[i][j]+min_path_sum(i-1,j+1,matrix,dp);
        return dp[i][j]=min({up,left_diagonal,right_diagonal});

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        for(int i=0;i<n;i++) dp[0][i]=matrix[0][i];

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 int up=matrix[i][j]+dp[i-1][j];
                 int left_diagonal= (j-1>=0) ? matrix[i][j]+dp[i-1][j-1] :1e9;
                 int right_diagonal=(j+1<m) ? matrix[i][j]+dp[i-1][j+1] :1e9;
                 dp[i][j]=min({up,left_diagonal,right_diagonal});

            }
        }
        // Find minimum in the last row
        int mini = 1e9;
        for(int j = 0; j < m; j++) {
            mini = min(mini, dp[n-1][j]);
        }
        return mini;   
    }
};

// Time Complexity:O(n × m) + O(n)  (for mini loop)
// Space Complexity:O(n × m)
