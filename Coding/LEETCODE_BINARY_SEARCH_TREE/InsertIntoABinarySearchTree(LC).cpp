// LEETCODE: 701. Insert into a Binary Search Tree 

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        TreeNode * current= root;

        while(current)
        {
            if(current->val<val)
            {
                if(current->right!=nullptr) current=current->right;
                else {
                current->right= new TreeNode(val);
                break;
                }
            }

            else{
                if(current->left!=nullptr) current=current->left;
                else {
                current->left= new TreeNode(val);
                break;
                }
            }
          
        }
        return root;
    }
};

// Time Complexity: O(h)
//  Space Complexity: O(1)
     
