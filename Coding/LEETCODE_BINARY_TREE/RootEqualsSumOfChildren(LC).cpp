// LEETCODE: 2236. Root Equals Sum of Children ( RECURSION )

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool checkTree(TreeNode* root) {
        if(!root) return true;
        if(!root->left && !root->right) return true;

        int left_data = root->left ? root->left->val : 0;
         int right_data = root->right ? root->right->val : 0;

         if(root->val!=(left_data+right_data)) return false;

         return checkTree(root->left) && checkTree(root->right);
        
    }
};
