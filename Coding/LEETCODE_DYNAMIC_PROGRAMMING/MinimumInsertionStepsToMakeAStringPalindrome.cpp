// LEETCODE: 1312. Minimum Insertion Steps to Make a String Palindrome  (DP,MEMOIZATION)

//NOTE: SEE  Longest Palindromic Subsequence TO SOLVE THIS PROBLEM
// DO IT USING SPACE OPTIMIZATION AND TABULATION

//MEMOIZATION
class Solution {
public:
     int LPS(int index1, int index2, string &text1, string &text2, vector<vector<int>> &dp) {
        if (index1 < 0 || index2 < 0) return 0;
        if (dp[index1][index2] != -1) return dp[index1][index2];

        if (text1[index1] == text2[index2]) {
            return dp[index1][index2] = 1 + LPS(index1 - 1, index2 - 1, text1, text2, dp);
        }
        return dp[index1][index2] = max(LPS(index1 - 1, index2, text1, text2, dp),
                                        LPS(index1, index2 - 1, text1, text2, dp));
    }
    int minInsertions(string s) {
        int n=s.length();
        string s2=s;
        reverse(s2.begin(),s2.end());
        vector<vector<int>>dp(n,vector<int>(n,-1));
//  Minimum Insertion Steps to Make a String Palindrome= n - LPS    
    return n - LPS(n-1,n-1,s,s2,dp);

    }
};
//  Time Complexity: O(n^2)
// Space Complexity: O(n^2)+O(n)=O(n^2)
