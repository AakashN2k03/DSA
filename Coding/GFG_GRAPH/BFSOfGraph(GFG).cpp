// GFG: BFS of graph ( BFS )

// IN GRAPH BEFORE SOLVING , READ THE INPUT FORMAT PROPERLY

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        int size=adj.size();
        vector<int>vis(size,0);
        
        vis[0]=1; // since first node / vertex
        
        queue<int> qu;
        qu.push(0);
        vector<int>bfs;
        while(!qu.empty())
       {
           int node=qu.front();
           qu.pop();
           bfs.push_back(node);
           for(auto it:adj[node])
           {
               if(!vis[it])
               {
                   vis[it]=1;
                   qu.push(it);
               }
           }
       } 
       return bfs;
    }
};

// ✅ Space Complexity: O(V)
// Why?

// visited[] array of size V ⇒ O(V)
// queue may contain up to V nodes ⇒ O(V)
// result vector stores the traversal (up to V elements) ⇒ O(V)  -> total O(3V).
// So total space is O(V).(neglect 3)

// ✅ Time Complexity: O(V + E)
  
// V: Number of vertices (nodes).
// E: Number of edges.
// Why?

// Each node is visited once ⇒ O(V).
// Each edge is considered once (for undirected graphs, each edge appears in two adjacency lists) ⇒ O(2E) becomes O(E).

