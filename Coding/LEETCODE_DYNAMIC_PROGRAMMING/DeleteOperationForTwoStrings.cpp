// LEETCODE: 583. Delete Operation for Two Strings (DP,MEMOIZATION)

//NOTE: SEE LCS BEFORE SOLVING THIS PROBLEM
// DO THIS USING SPACE AND TABULATION METHOD
// MEMOIZATION

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

    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int LCS=fn(n,m,word1,word2,dp);
        int word1_deletion=n-LCS;
        int word2_deletion=m-LCS;
        return word1_deletion+ word2_deletion;

    }
};
// Time Complexity: O(n × m)
// Space Complexity:O(n × m) (DP) + O(n + m) (stack)
