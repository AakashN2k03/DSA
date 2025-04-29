// STRIVER SHEET: Frog Jumps With K Distance (DP,MEMOIZATION,TABULATION)

// MEMOIZATION
class Solution {
public:
    int solve(int idx, int k, vector<int>& height, vector<int>& dp) {
        if (idx == 0) return 0;
        if (dp[idx] != -1) return dp[idx];

        int minCost = INT_MAX;
        for (int j = 1; j <= k; ++j) {
            if (idx - j >= 0) {
                int cost = solve(idx - j, k, height, dp) + abs(height[idx] - height[idx - j]);
                minCost = min(minCost, cost);
            }
        }
        return dp[idx] = minCost;
    }

    int minCost(int n, int k, vector<int>& height) {
        vector<int> dp(n, -1);
        return solve(n - 1, k, height, dp);
    }
};
// TIME COMPLEXITY: O(N * K)
// SPACE COMPLEXITY:O(N)+O(N)

// TABULATION
class Solution {
public:
    int minCost(int n, int k, vector<int>& height) {
        vector<int> dp(n, 0);
        dp[0] = 0;  // cost to reach the first stone is 0

        for (int i = 1; i < n; ++i) {
            int minCost = INT_MAX;
            for (int j = 1; j <= k; ++j) {
                if (i - j >= 0) {
                    int cost = dp[i - j] + abs(height[i] - height[i - j]);
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }

        return dp[n - 1];
    }
};
// TIME COMPLEXITY: O(N * K)
// SPACE COMPLEXITY:O(N)
