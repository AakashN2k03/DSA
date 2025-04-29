// LEETCODE: 198. House Robber (DP,MEMOIZATION,TABULATION)

//MEMOIZATION
class Solution {
public:
   int robber_house(int n,vector<int>& nums,vector<int>& dp)
   { 
    if(n==0) return nums[0];
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    
    int pick=nums[n]+robber_house(n-2,nums,dp);
    int notpick=0+robber_house(n-1,nums,dp);
   
    return dp[n]=max(pick,notpick);

   }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return robber_house(n-1,nums,dp);
    }
};
TIME COMPLEXITY: O(N)
SPACE COMPLEXITY:O(N)+O(N)

// TABULATION
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            int pick=nums[i];
            if(i>1) pick+=dp[i-2];
            int notpick=0+dp[i-1];
            dp[i]=max(pick,notpick);
        }
        return dp[n-1];
    }
};
TIME COMPLEXITY: O(N)
SPACE COMPLEXITY:O(N)

// MOST OPTIMIZED
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0];
        int prev2=0; // to avoid negative
        for(int i=1;i<n;i++)
        {
            int pick=nums[i];
            if(i>1) pick+=prev2;
            int notpick=0+prev;
            int maxi=max(pick,notpick);
            prev2=prev;
            prev=maxi;

        }
        return prev;
    }
};
TIME COMPLEXITY: O(N)
SPACE COMPLEXITY:O(1)
