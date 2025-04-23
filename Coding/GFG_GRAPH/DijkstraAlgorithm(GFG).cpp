// LEETCODE: Dijkstra Algorithm (SHORTEST PATH) (DIJKSTRA , SET)

// NOTE: THIS PROBLEM IS BASED ON UNDIRECTED ,WEIGHTED GRAPH

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
      vector<vector<pair<int,int>>> adjls(V);

      
      for(auto edge:edges)
      {   
          int u=edge[0];
          int v=edge[1];
          int wt=edge[2];
          
            adjls[u].push_back({v, wt});
            adjls[v].push_back({u, wt}); 
      }
      vector<int>distance(V,INT_MAX);
      distance[src]=0;
      set<pair<int,int>> st;
      st.insert({0,src}); // WEIGHT , NODE
      
      while(!st.empty())
      {
          auto it =*(st.begin());
          int node=it.second;
          int wt=it.first;
          st.erase(it);
          
          for(auto neighbour:adjls[node])
          {
              int adjnode=neighbour.first;
              int wt=neighbour.second;
              
              if(distance[node]+wt < distance[adjnode])
              {
                  if(distance[adjnode]!=INT_MAX) //ALREADY NEIGHBOUR VISISTED
                  {
                    st.erase({distance[adjnode],adjnode});
                  }
                  
                   distance[adjnode]=distance[node]+wt;
                   st.insert({distance[adjnode],adjnode}); // add newn node to set if it has less or not visited already
              
              }
             
          }   

      }
      return distance;  
    }
};

// Time Complexity: O(E⋅logV)
// E is the number of edges, this step takes O(E).

// You insert and remove nodes from a set (min-priority queue). For each node:
// -> Insert operation takes O(log V).
// -> Erase operation takes O(log V).

// Space Compleity: O(E+V)
