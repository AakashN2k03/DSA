// GFG: Kth largest element in BST (INORDER IN REVERSE)

class Solution {
  public:
   void reverseInorder(Node* root,int k,int& count,int& largest)
   {
       if(!root || count>=k) return;
       reverseInorder(root->right,k,count,largest);
       
       count++;
       
       if(count==k)
       {
           largest=root->data;
       }
        reverseInorder(root->left,k,count,largest);
       
   }
    int kthLargest(Node *root, int k) {
        int count,largest;
        count=0;
        largest=-1;
        reverseInorder(root,k,count,largest);
        return largest;
    }
};
// Time Complexity: O(n)
//  Space Complexity: O(n)
