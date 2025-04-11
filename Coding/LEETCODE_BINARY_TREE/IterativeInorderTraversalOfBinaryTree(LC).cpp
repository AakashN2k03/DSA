LEETCODE: 94. Binary Tree Inorder Traversal (STACK)  // WITHOUT RECURSION

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

// Iterative method is preferref for large input as stack used heap memory
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;
        TreeNode* node=root;
        while(true)
        {
            if(node!=nullptr)
            {
                st.push(node);
                node=node->left;
            }
            else{
                if(st.empty()) break;
                node=st.top();
                st.pop();
                ans.push_back(node->val);
                node=node->right;
            }
        }
        return ans;
    }
};

//Time Complexity: O(N)
// Space complexity

// Auxiliary Space (Explicit Stack):

// Best Case (Balanced Tree): O(log N)

// Worst Case (Skewed Tree): O(N)
