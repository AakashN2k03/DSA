// GFG: Topological sort (DFS)

// Topological Sort is a linear ordering of the vertices of a Directed Acyclic Graph (DAG) 
// such that for every directed edge u → v, vertex u comes before vertex v in the ordering.

// ✅ Conditions:
// The graph must be Directed
// The graph must be Acyclic (no cycles)

// 🧠 Example:
// 0 → 1
// 0 → 2
// 1 → 3
// 2 → 3
  
// One possible topological sort:0 1 2 3
// Another possibility :0 2 1 3


class Solution {
public:
    void dfs(int node, stack<int>& st, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;
        for(int adjnode : adj[node]) {
            if(!vis[adjnode]) {
                dfs(adjnode, st, vis, adj);
            }
        }
        st.push(node);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);
        for(auto& edge : edges) {
         
            adj[edge[0]].push_back(edge[1]);
        }
        
        vector<int> vis(V, 0);
        stack<int> st;
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, st, vis, adj);
            }
        }
        
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};

// Time Complexity: O(V + E)
// Space Complexity: O(V)
