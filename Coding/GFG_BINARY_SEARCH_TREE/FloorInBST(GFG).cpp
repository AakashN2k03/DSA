// GFG: Floor in BST 

class Solution{

public:
    int floor(Node* root, int x) {
    if (!root) return -1;
    
    int floor=-1;
    while(root)
    {
       if(x==root->data)
       {
           floor=root->data;
           return floor;
       }
       else if(x>root->data)
       {   floor=root->data;
           root=root->right;
           
       }
       else{
           root=root->left;
       }
    }
    return floor;
    }
};
// Time Complexity: O(h)
//  Space Complexity: O(1)
