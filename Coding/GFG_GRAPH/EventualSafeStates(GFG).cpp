// GFG:  Eventual Safe States ( DFS )

// SEE CYCLE DETECTION PROBLEM TO SOLVE THIS PROBLEM

// CONDITION FOR NODES THAT ARE NOT SAFER NODES :
// 1. ANYONE WHO IS PART OF A CYCLE IS NOT A SAFE NODE
// 2. THE NODE LEADS TO CYCLE OR IT HAS OUTGOING EDGE TO CYCLE 

class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>& path_vis, vector<int> adj[], vector<int>& check) {
        vis[node] = 1;
        path_vis[node] = 1;
        for (int adjnode : adj[node]) {
            if (!vis[adjnode]) {
                if (dfs(adjnode, vis, path_vis, adj, check)) {
                    check[node] = 0;
                    return true;
                }
            } else if (path_vis[adjnode] == 1) {
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        path_vis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // vector<int> adj[] same as vector<vector<int>>adjls(V)
        vector<int> vis(V, 0);
        vector<int> path_vis(V, 0);
        vector<int> check(V, 0);
        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, path_vis, adj, check);
            }
        }
        for (int i = 0; i < V; i++) {
            if (check[i] == 1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// Time Complexity: O(V + E)
// Space Complexity: O(V)
