// GFG: Directed Graph Cycle (DFS)

// DO THIS PROBLEM USING SINGLE VIS ARRAY
// IF POSSIBLE DO IT ON USING BFS

// CONDITION : ON THE SAME PATH THE NODE HAS TO BE VISITED AGAIN,THEN THERE IS A CYCLE EXISTS IN A DIRECTED GRAPH

class Solution {
  public:
    bool dfs(int node,vector<int>&vis,vector<int>& path_vis,vector<vector<int>>& adjls)
    {
        vis[node]=1;
        path_vis[node]=1;
        
        for(int adjnode:adjls[node])
        {
            if(!vis[adjnode])  // If adjacent node not visited, recurse
            {
                if(dfs(adjnode,vis,path_vis,adjls)) return true;
            }
            // If adjacent node is visited and is in the current DFS path → cycle
            else if(path_vis[adjnode]==1) return true; 
        }
        path_vis[node]=0; // Backtrack: remove node from current DFS path
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        vector<vector<int>> adjls(V);
        
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            adjls[u].push_back(v); //since it's a directed graph
           
        }
        vector<int>vis(V,0);
        vector<int>path_vis(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,path_vis,adjls)) return true;
            }
        }
        return false;
        
    }
};

// Time Complexity: O(V + E)
// Space Complexity: O(V)
