// GFG: Frog Jump (DP,MEMOIZATION,TABULATION)

// MEMOIZATION
class Solution {
  public:
   int frog_jump(int n,vector<int>& height,vector<int>&dp)
   {
       if(n==0) return 0;
       if(dp[n]!=-1) return dp[n];
       
       int left=frog_jump(n-1,height,dp)+ abs(height[n-1]-height[n]);
       int right=INT_MAX;
       if(n>1)
       {
        right =frog_jump(n-2,height,dp)+abs(height[n-2]-height[n]);
       }
       
       return dp[n] = min(left, right);
   }
    int minCost(vector<int>& height) {
      
        int n=height.size();
        vector<int>dp(n,-1);
        return frog_jump(n-1,height,dp); // start with last index
    }
};
// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY:O(N)+O(N) (stack space)

//TABULATION
class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int>dp(n,-1);
        dp[0]=0;
       
        for(int i=1;i<n;i++)
        {
         int left=dp[i-1]+abs(height[i]-height[i-1]);
            int right=INT_MAX;
            if(i>1)
            {
             right=dp[i-2]+abs(height[i]-height[i-2]);
            }
           dp[i]=min(left,right);
        }
        return dp[n-1];
    }
};
// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY:O(N)

// MOST OPTIMIZED
class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        int prev=0;
        int prev2=0;
        for(int i=1;i<n;i++)
        {
            int left=prev+abs(height[i]-height[i-1]);
            int right=INT_MAX;
            if(i>1)
            {
             right=prev2+abs(height[i]-height[i-2]);
            }
         int minima=min(left,right);
         prev2=prev;
         prev=minima;
        }
        return prev;
    }
};
// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY:O(1)
