// GFG: Undirected Graph Cycle ( DFS)

class Solution {
  public:
    bool dfs(int node,int parent,vector<int>& vis, vector<vector<int>> & adjls)
    {
        vis[node]=1;
        
        for(auto it:adjls[node])
        {
            if(!vis[it])
            {
                if(dfs(it,node,vis,adjls)) return true;
            }
            else if(it!=parent) return true; //cycle detection
        }
        
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
      vector<vector<int>> adjls(V);
      for(auto edge:edges)
      {
          int u=edge[0];
          int v=edge[1];
          adjls[u].push_back(v);
          adjls[v].push_back(u);
      }
      vector<int>vis(V,0);
      
      for(int i=0;i<V;i++)
      {
          if(!vis[i])
          {
              if(dfs(i,-1,vis,adjls)) return true;
          }
      }
      return false;
    }
};

// Time Complexity: O(V + E)
// Space Complexity: O(N)
