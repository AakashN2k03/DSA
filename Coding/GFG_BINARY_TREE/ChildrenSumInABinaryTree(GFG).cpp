// GFG: Children Sum in a Binary Tree ( RECURSION )

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
        if(!root) return true;
        if(!root->left && !root->right) return true;

        int left_data = root->left ? root->left->data : 0;
         int right_data = root->right ? root->right->data : 0;

         if(root->data!=(left_data+right_data)) return false;

         return isSumProperty(root->left) && isSumProperty(root->right);
        
    }
};
