// GFG: Ceil in BST 

int findCeil(Node* root, int input) {
    if (root == NULL) return -1;

    // Your code here
    int ceil=-1;
    
    while(root)
    {
        if(input==root->data)
        {
            ceil=root->data;
            return ceil;
        }
        
        else if(input<root->data)
        {  ceil=root->data;
            root=root->left;
            
        }
        else{
   
            root=root->right; // don't update ceil because current value is less than input, and can't be ceil.

        }
        
    }
    return ceil;
}
