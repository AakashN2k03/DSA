// GFG: Knapsack with Duplicate Items (UNBOUNDED KNAPSACK) (DP,MEMOIZATION,KNAPSACK)

// NOTE: FIRST SEE  0 - 1 Knapsack Problem TO SOLVE THIS ,THERE IS A LIGHT CHANGE IN THIS PROBLEM BASE CONDITION AND PICK LOGIC
// DO THIS USING TABULATION AND SPACE OPTIMIZATION

//MEMOIZATION
class Solution {
     int fn(int index,int weight,vector<int> &val,vector<int> &wt,vector<vector<int>>&dp)
   {
       if(index==0)
       {
          return (weight/wt[0])*val[0];
       }
       if(dp[index][weight]!=-1) return dp[index][weight];
       int not_pick=0+fn(index-1,weight,val,wt,dp);
       int pick=INT_MIN;
       if(wt[index]<=weight)
       {
           pick=val[index]+fn(index,weight-wt[index],val,wt,dp);
       }
       
       return dp[index][weight]=max(pick,not_pick);
   }
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
         int n=wt.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
       return  fn(n-1,capacity,val,wt,dp);
    
    }
};
// Time complexity: O(n * W)
// Space complexity: O(n * W) + O(n) for recursion stack
