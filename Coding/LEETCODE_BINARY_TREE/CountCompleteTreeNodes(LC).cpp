// LEETCODE: 222. Count Complete Tree Nodes

 //  OPTIMIZED WAY
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
int leftheight(TreeNode* node)
{
    int height=0;
    while(node)
    {
        height++;
        node=node->left;
    }
    return height;
}

int rightheight(TreeNode* node)
{
    int height=0;
    while(node)
    {
        height++;
        node=node->right;
    }
    return height;
}
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
       int lh=leftheight(root);
       int rh=rightheight(root);

        if(lh==rh) return (1<<lh)-1 ;// if lh==rh then height of the tree 2^h -1

        return 1+countNodes(root->left)+countNodes(root->right);
        
    }
};

// BRUTE FORCE (INORDER)
class Solution {
  public:
    int countNodes(Node* root) {
        int count = 0;
        inorder(root, count);
        return count;
    }

    void inorder(Node* node, int& count) {
        if (!node) return;

        inorder(node->left, count);
        count++;
        inorder(node->right, count);
    }
};
