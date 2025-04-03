// GFG: Bottom View of Binary Tree (QUEUE, MAP, BFS)

class Solution {
  public:
    vector <int> bottomView(Node *root) {
       map<int,int>mpp;              // LINE , NODE->VALUE
       queue<pair<Node *,int>> qu;   // NODE , LINE
       
       qu.push({root,0});
       
       while(!qu.empty())
       {
           auto p=qu.front();
           qu.pop();
           
           Node * temp=p.first;
           int line=p.second;
           
           mpp[line]=temp->data;
           
           if(temp->left!=nullptr) qu.push({temp->left,line-1});
           if(temp->right!=nullptr) qu.push({temp->right,line+1});
           
       }
       vector<int>ans;
       for(auto it:mpp)
       {
           ans.push_back(it.second);   
       }
       return ans;
    }
};
