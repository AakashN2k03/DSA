// GFG: Bipartite Graph (BFS)

//CONDITION FOR BIPARTITE:

// Graph can be colored with two colors
// No odd-length cycles:

class Solution {
  public:
    bool bfs(int start,vector<int>&vis,vector<vector<int>> &adjls)
    {
        vis[start]=0;
        queue<int>qu;
        qu.push(start);
        while(!qu.empty())
        {
            int node=qu.front();
            qu.pop();
            for(auto adjnode:adjls[node])
            {
                 if(vis[adjnode]==-1)
                 {
                     vis[adjnode]=!vis[node];// alternate color 
                     qu.push(adjnode);
                 }
                 else if(vis[adjnode]==vis[node]) return false;// same color for adjancey node return false
            }
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
        vector<int>vis(V,-1);
        for(int i=0;i<V;i++)
        {  if(vis[i]==-1)
           {
            if(!bfs(i,vis,adjls)) return false; 
            // you immediately return false if any component is not bipartite (!bfs() returns true). If all components pass the check, you return true at the end.
           }
        }
        return true;
        
    }
};

// Time Complexity: O(V + E)
// Space Complexity: O(V)
