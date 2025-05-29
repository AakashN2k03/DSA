// GFG: Left View of Binary Tree ( DFS, RECURSION)

// SAME AS RIGHT VIEW .JUST SINGLE CHANGE.

class Solution {
  public:
   void left(Node* root,int level,vector<int>& ans)
   {
    if(!root) return;
    if(ans.size()==level) ans.push_back(root->data);
    left(root->left,level+1,ans);  // HERE IS THE CHANGE
    left(root->right,level+1,ans);

   }
    vector<int> leftView(Node *root) {
      vector<int> ans;
        int level=0;
        left(root,level,ans);
        return ans;
    }
};
