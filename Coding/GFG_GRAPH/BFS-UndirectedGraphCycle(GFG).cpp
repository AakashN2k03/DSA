// GFG: Undirected Graph Cycle ( BFS )

class Solution { 
public:
    bool bfs(int src, vector<int>& vis, vector<vector<int>>& adj)
    {
        vis[src] = 1;
        queue<pair<int, int>> qu;
        qu.push({src, -1});

        while (!qu.empty())
        {
            int node = qu.front().first;
            int parent = qu.front().second;
            qu.pop();

            for (auto adjnode : adj[node])
            {
                if (!vis[adjnode])
                {
                    vis[adjnode] = 1;
                    qu.push({adjnode, node});
                }
                else if (adjnode != parent) //deep dive using grok,since using bfs we can attain single node twice
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges)
    {
        vector<vector<int>> adj(V);
        for (auto& edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // undirected
        }

        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (bfs(i, vis, adj)) return true;
            }
        }
        return false;
    }
};

// Time Complexity: O(V + E)
// Space Complexity: O(N)
