// GFG: 0 - 1 Knapsack Problem (DP,MEMOIZATION,KNAPSACK)

// NOTE: DO THIS USING TABULATION AND SPACE OPTIMIZATION

class Solution {
  public:
   int fn(int index,int weight,vector<int> &val,vector<int> &wt,vector<vector<int>>&dp)
   {
       if(index==0)
       {
           if(wt[index]<=weight) return val[index];
           else return 0;
       }
       if(dp[index][weight]!=-1) return dp[index][weight];
       int not_pick=0+fn(index-1,weight,val,wt,dp);
       int pick=INT_MIN;
       if(wt[index]<=weight)
       {
           pick=val[index]+fn(index-1,weight-wt[index],val,wt,dp);
       }
       
       return dp[index][weight]=max(pick,not_pick);
   }
    int knapsack(int w, vector<int> &val, vector<int> &wt) {
        int n=wt.size();
        vector<vector<int>>dp(n,vector<int>(w+1,-1));
       return  fn(n-1,w,val,wt,dp);
    }
};
//here weight represent bag total weight
// wt is the arr of weights to be robbed
// value is the worth of items(wt) to be robbed

//Time complexity:O(n * W)
//Space complexity: O(n * W) +O(n) for stack space
