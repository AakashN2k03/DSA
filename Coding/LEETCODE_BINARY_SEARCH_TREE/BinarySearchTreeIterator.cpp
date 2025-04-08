// LEETCODE: 173. Binary Search Tree Iterator ( STACK )

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
class BSTIterator {
    private:
    stack<TreeNode*> st;

public:
    BSTIterator(TreeNode* root) {
       pushAll(root); 
        
    }
    
    int next() {
     TreeNode* temp=st.top();
     st.pop();
     pushAll(temp->right);
     return temp->val;
        
    }
    
    bool hasNext() {
        
        return !st.empty();
    }

    void pushAll(TreeNode* node)
    {
        while(node!=nullptr)
        {
            st.push(node);
            node=node->left;
        }
    }
};
