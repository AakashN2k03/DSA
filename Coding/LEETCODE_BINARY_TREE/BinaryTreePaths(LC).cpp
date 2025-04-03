// LEETCODE: 257. Binary Tree Paths (RECURSION)

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
     void root_to_leaf_path(TreeNode* node,string temp,vector<string>& ans)
     {
        if(!node) return;
        if(!temp.empty()) temp+="->";
        temp+=to_string(node->val);


        if(!node->left && ! node->right) ans.push_back(temp);

        root_to_leaf_path(node->left,temp,ans);
        root_to_leaf_path(node->right,temp,ans);

        temp.pop_back();

     }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        root_to_leaf_path(root,"",ans);
        return ans;
        
    }
};
