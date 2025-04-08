// LEETCODE: 653. Two Sum IV - Input is a BST (RECURSION)

// DO OPTIMIZED APPROACH BY USING BST ITERATOR ..SEE STRIVER

class Solution {
public:
   unordered_set<int>sett;
    bool findTarget(TreeNode* root, int k) {
 
    if(!root) return false;

    if(sett.count(k-root->val)) return true;    // a+b = k  which can also be written as k - b = a
    sett.insert(root->val);

    return findTarget(root->left,k)|| findTarget(root->right,k);
        
    }
};
