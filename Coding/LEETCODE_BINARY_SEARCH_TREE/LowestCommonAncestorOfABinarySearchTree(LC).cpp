// LEETCODE: 235. Lowest Common Ancestor of a Binary Search Tree (RECURSION)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr) return root;

        if(root->val < p->val && root->val < q->val)
        {
            return lowestCommonAncestor(root->right,p,q);
        }
        if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        return root;

        
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
