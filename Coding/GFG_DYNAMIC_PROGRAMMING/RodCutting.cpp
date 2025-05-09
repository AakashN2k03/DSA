// GFG: Rod Cutting (UNBOUNDED KNAPSACK) (DP,MEMOIZATION,KNAPSACK)

//NOTE: DO THIS USING TABULATION AND SPACE OPTIMIZATION
//AGAIN SEE WHY THE BELOW BASE CASE USED, DRY RUN TOO

class Solution {
public:
     int dpFn(int index, int remainingLength, vector<int>& price, vector<vector<int>>& dp) {
        if(index == 0) {
            return (remainingLength) * price[0];
        }

        if(dp[index][remainingLength] != -1) return dp[index][remainingLength];

        int not_pick = dpFn(index - 1, remainingLength, price, dp);

        int pick = INT_MIN;
        int rodLength = index + 1;
        if(rodLength <= remainingLength) {
            pick = price[index] + dpFn(index, remainingLength - rodLength, price, dp); // unbounded!
        }

        return dp[index][remainingLength] = max(pick, not_pick);
    }
    int cutRod(vector<int> &price)  {
        int n=price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return dpFn(n - 1, n, price, dp);
    }
};
// Time complexity: O(n * W)
// Space complexity: O(n * W) + O(n) for recursion stack
