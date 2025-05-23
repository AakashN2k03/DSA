// LEETCODE: 99. Recover Binary Search Tree ( INORDER )

// Eg: GIVEN TREE -> 3,2,1
// ACTUAL ANSWER ->  1,2,3 BY INORDER

class Solution {
public:
    TreeNode* first=nullptr;
    TreeNode* second=nullptr;
    TreeNode* prev=nullptr;
    void  inorder(TreeNode* root)
    {
        if(!root) return ;
        
        inorder(root->left);

        if(prev && prev->val > root->val)
        {
            if(!first)
            {
                first=prev;
            }
            second=root;
        }

        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {

      inorder(root);
      if(first && second)
      {
        swap(first->val,second->val);
      }
        
    }
};
