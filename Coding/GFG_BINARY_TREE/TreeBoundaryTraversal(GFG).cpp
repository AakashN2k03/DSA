// GFG: Tree Boundary Traversal (RECURSION + DFS)

// STEPS 

// 1. LEFT BOUNDARY NODE VALUES EXCLUDING LEAF NODES
// 2. INCLUDE LEAF NODES (INORDER TRAVERSAL)
// 3. RIGHT BOUNDARY NODE VALUES IN REVERSE EXCLUDING LEAF NODES

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
  bool isLeaf(Node *root)
  {
      return !root->left && !root->right;
  }
  
  void left_subtree_excluding_leaf_nodes(Node *current,vector<int>& res)
  {
     current=current->left;
     while(current)
     {
     if(!isLeaf(current))  res.push_back(current->data);
     
     if(current->left)     current=current->left;
     
     else current=current->right;
     }

  }
  void right_subtree_excluding_leaf_node(Node *current,vector<int>& res)
  {
      current=current->right;
      vector<int>temp;
      while(current)
      {
         if(!isLeaf(current))  temp.push_back(current->data);
         
         if(current->right)     current=current->right;
         
         else current=current->left;
         
      }
     for(int i=temp.size()-1;i>=0;i--)
     {
         res.push_back(temp[i]);
     }
      
  }
  
  void leaf_nodes(Node *current,vector<int>& res)  // INORDER TRAVERSAL
  {
      if(isLeaf(current)) 
      { res.push_back(current->data);
        return;
      }
      
      if(current->left) leaf_nodes(current->left,res);
      if(current->right) leaf_nodes(current->right,res);
      
  }
  
    vector<int> boundaryTraversal(Node *root) {
        vector<int>res;
        
        if(!root) return res;
        if(!isLeaf(root)) res.push_back(root->data);
        
        left_subtree_excluding_leaf_nodes(root,res);
        leaf_nodes(root,res);
        right_subtree_excluding_leaf_node(root,res);
        return res;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)
