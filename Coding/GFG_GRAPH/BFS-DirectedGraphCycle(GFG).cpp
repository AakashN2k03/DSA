// GFG: Directed Graph Cycle ( KANN'S ALGORITHM / BFS)

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
     vector<int>indegree(V);
      vector<vector<int>> adjls(V);
      
      for(auto edge:edges)
      {
          int u=edge[0];
          int v=edge[1];
          adjls[u].push_back(v);
      }
      
     for(int i=0;i<V;i++)
     {
         for(auto adjnode:adjls[i])
         {
             indegree[adjnode]++;
         }
     }
     
     queue<int>qu;
     for(int i=0;i<V;i++)
     {
         if(indegree[i]==0) qu.push(i);
     }
     
     int counter=0;
     while(!qu.empty())
     {
         int node=qu.front();
         qu.pop();
         counter++;
         
         for(auto adjnode:adjls[node])
         {
             indegree[adjnode]--;
             
             if(indegree[adjnode]==0) qu.push(adjnode);
         }
     }
     
     if(counter==V) return false; // is (counter == no of vertices), then it is in topological sort(DAG) -> NO CYCLE ,  Else IT HAS CYCLE
     return true;
      
    }
};

// ✅ Time Complexity: O(V + E)
// ✅ Space Complexity: O(N)
