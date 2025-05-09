// LEETCODE: 518. Coin Change II (DP,MEMOIZATION)

// NOTE: DO THIS USING TABULATION AND SPACE OPTIMIZATION

// MEMOIZATION
class Solution {
public:
    int fn(int index,int target,vector<int>& coins,vector<vector<int>>& dp)
    {
        if(index==0)
        {
            return (target % coins[0]==0);
        }
        if(dp[index][target]!=-1) return dp[index][target];

        int not_pick=fn(index-1,target,coins,dp);

        int pick= 0;
        if(coins[index]<=target) pick=fn(index,target-coins[index],coins,dp);
        return dp[index][target]=pick+not_pick;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return fn(n-1,amount,coins,dp);
        
    }
};
// TIME COMPLEXITY:O(N*AMOUNT)
// SPACE COMPLEXITY:O(N*AMOUNT)+O(N)
