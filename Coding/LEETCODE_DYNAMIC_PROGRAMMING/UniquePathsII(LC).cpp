// LEETCODE: Unique Paths II ( DP,MEMOIZATION,TABULATION)

// MEMOIZATION

class Solution {
public:
    int uniqueII(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) return 0;
        if (i == 0 && j == 0) return 1;  // Start position
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int up = uniqueII(i - 1, j, obstacleGrid, dp);
        int left = uniqueII(i, j - 1, obstacleGrid, dp);

        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return uniqueII(n - 1, m - 1, obstacleGrid, dp);
    }
};

// TIME COMPLEXITY: O(N*M)
// SPACE Complexity: = O(m * n) (for dp) + O(m + n) (for recursion stack)
// But we usually consider the dominating term: O(m * n).

//TABULATION

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else if(i == 0 && j == 0) {
                    dp[i][j] = 1;
                }
                else {
                    int up = (i > 0) ? dp[i-1][j] : 0;
                    int left = (j > 0) ? dp[i][j-1] : 0;
                    dp[i][j] = up + left;
                }
            }
        }

        return dp[n-1][m-1];
    }
};

// TIME COMPLEXITY: O(N*M)
// SPACE COMPLEXITY:O(N*M)
