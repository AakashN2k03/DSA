LEETCODE: 94. Binary Tree Inorder Traversal (RECURSION)

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

//Most systems allow ~10,000 to 20,000 recursive calls (stack frames).->(10^5),suitable for less stack call problems
//So, if your tree has depth > 10,000, you're likely to hit a stack overflow.

class Solution {
public:
void inorder(TreeNode* node,vector<int>& result)
{
    if(!node) return; // node==NULL
    
    inorder(node->left,result);
    result.push_back(node->val);
    inorder(node->right,result);
}
    vector<int> inorderTraversal(TreeNode* root) {\
        vector<int>result;
        inorder(root,result);
        return result;
    }
};
// Time Complexity: O(N)
// space complexity

// Auxiliary Space (Call Stack):

// Best Case (Balanced Tree): O(log N)

// Worst Case (Skewed Tree): O(N)
