//LEETCODE: 700. Search in a Binary Search Tree 



class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
       
        while(root!=nullptr && val!=root->val)
        {
            root= val < root->val ? root->left : root->right;
        }
        return root;
    }
};
// time complexity: O(h) where h is height of BST
// space complexity: O(1)

