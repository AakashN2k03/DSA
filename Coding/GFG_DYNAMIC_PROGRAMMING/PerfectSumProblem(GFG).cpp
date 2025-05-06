GFG:Perfect Sum Problem (COUNT SUBSET WITH SUM K) (DP,MEMOIZATION)

//NOTE: DO THIS USING TABULATION AND SPACE OPTIMIZATION

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
    
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return fn(n - 1, target, arr, dp);
    }
};
//NOTE: ALWAYS EMPTY SUBSET == 0 .ie-> {]=0
// ⏱️ Time Complexity = O(n * target)
// 🧠 Space Complexity = O(n * target) + O(n) 
