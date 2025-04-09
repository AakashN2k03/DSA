// LEETCODE: 94. Binary Tree Inorder Traversal (MORRIS TRAVERSAL)

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* current=root;

        while(current!=nullptr)
        {
            if(current->left==nullptr)
            {
                inorder.push_back(current->val);
                current=current->right;
            }
            else{
                TreeNode* prev=current->left;

                // Find rightmost node in left subtree
                while(prev->right != nullptr && prev->right!=current)
                {
                    prev=prev->right;
                }

                if(prev->right==nullptr)
                {     // Make a thread
                    prev->right=current;
                   // preorder.push_back(current->val);  for preorder
                    current=current->left;
                }
                else{
                     // Thread already exists; remove it
                    prev->right=nullptr;
                    inorder.push_back(current->val);  // remove these when it is preorder problem
                    current=current->right;
                }
            }
        }
       return inorder;
    }
};
