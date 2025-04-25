// GFG: Bellman-Ford (BELLMANFORD ALGORITHM)

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> distance(V,1e8);
        distance[src]=0;
        for(int i=0;i<V-1;i++)
        {   // relaxing edges
           for(auto it:edges)
           {
               int u=it[0];
               int v=it[1];
               int wt=it[2];
               
               if(distance[u]!=1e8 && distance[u]+wt < distance[v])
               {
                   distance[v]=distance[u]+wt;
               }
           }
        }

// negative cycle -> intution behind below loop :
//1.If the graph has no negative cycles, then after these V-1 iterations, all shortest distances will be finalized.
//2.But if we can still relax any edge after V-1 iterations (i.e., distance[u] + wt < distance[v]), it means there's a negative weight cycle.
       
for(auto it:edges)
           {
               int u=it[0];
               int v=it[1];
               int wt=it[2];
               
               if(distance[u]!=1e8 && distance[u]+wt < distance[v])
               {
                   return {-1};
               }
           }
        return distance;
    }
};

// Time Complexity: O(V×E) // it is bit longer than dijkstra since it detects negative cycle where as dijkstra won't give annwer for negative cycle
// Space Complexity: O(V)
