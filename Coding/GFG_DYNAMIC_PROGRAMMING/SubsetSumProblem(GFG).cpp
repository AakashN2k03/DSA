// GFG: Subset Sum Problem (DP,MEMOIZATION)

//NOTE : DO THIS SUM USING TABULATION AND SPACE OPTIMIZATION TECHNIQUE
// SEE RECURSION PICK AND NOT PICK TOPIC AND DRY RUN BEFORE SOLVING THE BELOW PROBLEM

// MEMOIZATION
class Solution {
  public:
   bool recurse(int index,int target,vector<int>& arr,vector<vector<int>>&dp)
   {
       if(target==0) return true;
       if(index==0) return arr[0]==target;
       if(dp[index][target]!=-1) return dp[index][target];
       
      bool notpick=recurse(index-1,target,arr,dp);
      
      bool pick=false;
      if(arr[index]<=target) pick=recurse(index-1,target-arr[index],arr,dp);
      
      return dp[index][target]=pick|notpick;
   }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return recurse(n-1,sum,arr,dp);
    }
};

// ⏱️ Time Complexity = O(n * target)
// 🧠 Space Complexity = O(n * target) + O(n) 




