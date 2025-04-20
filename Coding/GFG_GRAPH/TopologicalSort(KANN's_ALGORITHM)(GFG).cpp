// GFG: Topological sort ( KANN's ALGORITHM / BFS)

// STEPS:
// 1. INCREMENT THE NODE WICH HAS INDEGREE
// 2. PUSH THE NODE WITH INDEGREE 0
// 3. POP THAT NODE
// 4. DECREMENT THE ADJACENT NODE OF THAT POPPED NODE(WHICH HAS 0 INDEGREE)  
// 5. AFTER SOMETIME THE DECREMENTED NODE BECOMES INDEGREE 0 AND THEN PUSH THAT IN QUEUE.
  
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
      
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
      {  if(indegree[i]==0)
        {
          qu.push(i);
        }
      }
      
      vector<int>ans;
      while(!qu.empty())
      {
          int node=qu.front();
          qu.pop();
          ans.push_back(node);
          
          for(auto adjnode:adjls[node])
          {
              indegree[adjnode]--;
              if(indegree[adjnode]==0) 
              {
                  qu.push(adjnode);
              }
          }
      }
      return ans;
    }
};

✅ Time Complexity: O(V + E)
✅ Space Complexity: O(V)
