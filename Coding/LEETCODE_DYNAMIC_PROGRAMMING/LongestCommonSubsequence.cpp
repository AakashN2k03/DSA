// LEETCODE: 1143. Longest Common Subsequence (DP,MEMOIZATION)
// DO THIS USING SPACE OPTIMIZATION AND TABULATION

 // NOTE: WE USE SHIFTING OF INDEX..WHY SEE STRIVER
class Solution {
public:
    int fn(int index1, int index2, string &text1, string &text2, vector<vector<int>> &dp) {
        if (index1 == 0 || index2 == 0) return 0;
        if (dp[index1][index2] != -1) return dp[index1][index2];

        if (text1[index1 - 1] == text2[index2 - 1]) {
            return dp[index1][index2] = 1 + fn(index1 - 1, index2 - 1, text1, text2, dp);
        }
        return dp[index1][index2] = max(fn(index1 - 1, index2, text1, text2, dp),
                                       fn(index1, index2 - 1, text1, text2, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return fn(n, m, text1, text2, dp);
    }
};

// Time Complexity:  O(n × m)
// Space Complexity: O(n × m)+O(n + m)
