// GFG: DFS of Graph ( RECURSION ,DFS )

class Solution {
  public:
  void dfs_traverse(int node,vector<int>& dfs_res,vector<int>& vis,vector<vector<int>>& adj)
  {
      vis[node]=1;
       dfs_res.push_back(node);
      for(auto it:adj[node])
      {
          if(!vis[it])
          {
              dfs_traverse(it,dfs_res,vis,adj);
          }
      }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        int size=adj.size();
       vector<int>vis(size,0);
       vector<int>dfs_res;
       int first_node=0;
       
       dfs_traverse(first_node,dfs_res,vis,adj);
       return dfs_res;
       
        
    }
};

// ✅ Time Complexity: O(V + E)

// ✅ Space Complexity: O(V)
// vis array → size V
// dfs_res → stores all V nodes
// Call stack (for recursion): In worst case (linear graph), stack depth = V
// So total space = O(V) + O(V) + O(V) = O(V)
