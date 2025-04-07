// GFG: Inorder Successor in BST 

class Solution {
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    int inOrderSuccessor(Node *root, Node *x) {
       int successor=-1;
       while(root!=NULL)
       {
           if(x->data >= root->data)
           {
               root=root->right;
           }
           else{
               successor=root->data;  // DRY RUN TO SEE HOW SUCCESSOR STORES THE VALUE
               root=root->left;
           }
       }
       return successor;
    }
};
// ✅ while (root != NULL)
// This means: "Continue looping as long as root is not null"

// ❌ while (!root)
// This means: "Continue looping while root IS null"

