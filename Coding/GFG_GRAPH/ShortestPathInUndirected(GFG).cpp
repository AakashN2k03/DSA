// GFG: Shortest Path in Undirected ( BFS )

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int V = adj.size();  // Number of vertices

        vector<int> distance(V, -1);  // Initialize all distances to -1
        distance[src] = 0;

        queue<int> qu;
        qu.push(src);

        while (!qu.empty()) {
            int node = qu.front();
            qu.pop();

            for (int neighbor : adj[node]) {
                if (distance[neighbor] == -1) {
                    distance[neighbor] = distance[node] + 1;
                    qu.push(neighbor);
                }
            }
        }
        return distance;
    }
};

Time Complexity:O(V + E)
Space Complexity:O(V + E)

