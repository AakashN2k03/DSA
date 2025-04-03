// GFG: Top View of Binary Tree ( BFS, MAP, QUEUE )

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    vector<int> topView(Node *root) {
      map<int,int> mpp;          // LINE , NODE->VALUE
      queue<pair<Node*,int>>qu;  // NODE , LINE
      qu.push({root,0});
      
      while(!qu.empty())
      {
          auto p=qu.front();
          qu.pop();
          
          Node* temp_node=p.first;
          int line=p.second;
          
          if(mpp.find(line)==mpp.end()) mpp[line]=temp_node->data;
          
          if(temp_node->left) qu.push({temp_node->left,line-1});
          if(temp_node->right) qu.push({temp_node->right,line+1});
          
      }
      vector<int>ans;
      for(auto it:mpp)
      {
          ans.push_back(it.second);
      }
      return ans;
    }
};
