// LEETCODE: 322. Coin Change (DP,MEMOIZATION)

// NOTE: DO THIS USING TABULATION AND SPACE OPTIMIZATION

class Solution {
public:
    int fn(int index,int amount,vector<int>& coins,vector<vector<int>>&dp)
    {
        if(index==0)
        {
            if(amount%coins[0]==0) return amount/coins[0];
            else return 1e9;
        }
        if(dp[index][amount]!=-1) return dp[index][amount];
        int  not_pick=0+fn(index-1,amount,coins,dp);
       int  pick=1e9;
        if(coins[index]<=amount) pick=1+fn(index,amount-coins[index],coins,dp);
        return dp[index][amount]=min(pick,not_pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=fn(n-1,amount,coins,dp);
        return ans>=1e9?-1:ans;
        // by the end of recursion, if no valid combination is found, ans will still be 1e9 or more.
    }
};
// TIME COMPLEXITY:O(N*AMOUNT)
// SPACE COMPLEXITY:O(N*AMOUNT)+O(N)
