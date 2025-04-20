// GFG: Shortest path in Directed Acyclic Graph ( TOPOLOGICAL SORT / DFS )

class Solution {
public:
    void dfs(int node, vector<vector<pair<int,int>>>& adjls, vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        
        for(auto adjnode : adjls[node]) {   
            int v = adjnode.first;
            if(!vis[v]) {
                dfs(v, adjls, vis, st);
            }
        }
        
        st.push(node);
    }
   
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Create adjacency list representation of the graph
        vector<vector<pair<int,int>>> adjls(V);
        
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adjls[u].push_back({v, wt});
        }
        
        // Perform topological sort using DFS
        vector<int> vis(V, 0);
        stack<int> st;
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, adjls, vis, st);
            }
        }
        
        // Initialize distances array
        vector<int> distance(V, INT_MAX);
        distance[0] = 0;
        
        // Process vertices in topological order and update distances
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            
            // If the node is reachable
            if(distance[node] != INT_MAX) {
                for(auto adjnode : adjls[node]) {
                    int v = adjnode.first;
                    int wt = adjnode.second;
                    
                    if(distance[node] + wt < distance[v]) {
                        distance[v] = distance[node] + wt;
                    }
                }
            }
        }
        
        // Convert unreachable nodes to -1
        for(int i = 0; i < V; i++) {
            if(distance[i] == INT_MAX) {
                distance[i] = -1;
            }
        }
        
        return distance;
    }
};

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)
