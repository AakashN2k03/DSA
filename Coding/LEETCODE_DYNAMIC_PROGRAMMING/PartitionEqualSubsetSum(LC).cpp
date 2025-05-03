// LEETCODE: 416. Partition Equal Subset Sum (DP,MEMOIZATION)

//NOTE : DO THIS SUM USING TABULATION AND SPACE OPTIMIZATION TECHNIQUE
//PREREQUISITE: WATCH SUBSET SUM PROBLEM TO SOLVE THIS PROBLEM

// MEMOIZATION
class Solution {
public:
   bool subset_sum(int index,int target,vector<int>& arr,vector<vector<int>>&dp)
   {
       if(target==0) return true;
       if(index==0) return arr[0]==target;
       if(dp[index][target]!=-1) return dp[index][target];
       
      bool notpick=subset_sum(index-1,target,arr,dp);
      
      bool pick=false;
      if(arr[index]<=target) pick=subset_sum(index-1,target-arr[index],arr,dp);
      
      return dp[index][target]=pick|notpick;
   }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int tot_sum=0;
        for(int i=0;i<n;i++) tot_sum+=nums[i];

        if(tot_sum%2!=0) return false; // odd
        //if even
        int target=tot_sum/2;
        
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return subset_sum(n-1,target,nums,dp);

    }
};

// ⏱️ Time Complexity = O(n * target)+O(n)
// 🧠 Space Complexity = O(n * target) + O(n) 

