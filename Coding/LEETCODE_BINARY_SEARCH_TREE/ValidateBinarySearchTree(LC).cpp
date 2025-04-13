// LEETCODE: 98. Validate Binary Search Tree 

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
   bool checkisValidBST(TreeNode* node,long min_val,long max_val)
   {
       if(!node) return true;
       if(node->val <= min_val || node->val >= max_val) return false;

       return checkisValidBST(node->left,min_val,node->val) && checkisValidBST(node->right,node->val,max_val);
   }
    bool isValidBST(TreeNode* root) {
        return checkisValidBST(root,LONG_MIN,LONG_MAX);
    }
};
//  Time Complexity: O(n)
// Space Complexity: O(n)
