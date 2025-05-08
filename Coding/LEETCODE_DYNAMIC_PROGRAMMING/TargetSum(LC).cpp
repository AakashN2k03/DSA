// LEETCODE: 494. Target Sum (DP,MEMOIZATION)

// NOTE: DO THIS USING TABULATION AND SPACE OPTIMIZATION
// IT IS EXACTLY SAME PROBLEM AS Partitions with Given Difference 

//MEMOIZATION
class Solution {
public:
 int fn(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (index == 0) {
            if (target == 0 && arr[0] == 0) return 2; // dry run ,arr = {0}, target = 0 and arr = {0,0}, target = 0

            if (target == 0 || arr[0] == target) return 1; //dry run arr = {5}, target = 0 

            return 0;
        }
        if (dp[index][target] != -1) return dp[index][target];
        
        int not_pick = fn(index - 1, target, arr, dp);
        
        int pick = 0;
        if (arr[index] <= target) {
            pick = fn(index - 1, target - arr[index], arr, dp);
        }
        
        return dp[index][target] = pick + not_pick;
    }
    int countPartitions(vector<int>& arr, int d) {
        int tot_sum=0;
        for(int num:arr) tot_sum+=num;
        
        if(tot_sum-d<0 || (tot_sum-d)%2!=0) return 0;
        
        int n = arr.size();
        int target=(tot_sum-d)/2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return fn(n - 1, target, arr, dp);
     
    }
    int findTargetSumWays(vector<int>& nums, int target) {
     return countPartitions(nums,target);
        
    }
};

//Time complexity:o(n*target)+o(n) for sum loop=o(n*target);
//space complexity:o(n*target)+o(n)
