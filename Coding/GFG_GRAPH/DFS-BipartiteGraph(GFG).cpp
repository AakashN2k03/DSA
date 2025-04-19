// GFG: Bipartite Graph ( DFS )

class Solution {
  public:
    bool dfs(int start_node,int color,vector<int>&vis,vector<vector<int>> &adjls)
    {
       vis[start_node]=color;
       for(int adjnode:adjls[start_node])
       {
           if(vis[adjnode]==-1)
           {
               if(dfs(adjnode,!color,vis,adjls)==false) return false;
           }
           
           else if(vis[adjnode]==vis[start_node]) return false;
       }
       return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        
        vector<vector<int>>adjls(V);
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            adjls[u].push_back(v);
            adjls[v].push_back(u);
        }
        int color=0;
        vector<int>vis(V,-1);
        for(int i=0;i<V;i++)
        {  if(vis[i]==-1)
           {
            if(!dfs(i,color,vis,adjls)) return false;
           }
        }
        return true;
        
    }
};

// ✅ Time Complexity: O(V + E)
// ✅ Space Complexity: O(V)
