// GFG: Floyd Warshall (FLOYD WARSHALL)


// 💥The Floyd-Warshall algorithm is a dynamic programming algorithm used to:
// ✅ Find the shortest distance between every pair of nodes in a weighted graph (can be directed or undirected).
// Graph may contain negative weights (but it is not suitable for  negative cycles)
  
class Solution {
public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        
        for (int via = 0; via < n; ++via) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    // Check if path i -> k and k -> j exists
                    if (dist[i][via] < 1e8 && dist[via][j] < 1e8) {
                        dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                    }
                }
            }
        }
         // Detect negative cycles
        //  for (int i = 0; i < n; ++i) {
        //     if (dist[i][i] < 0) {
        //         // Negative cycle detected
        //         // You can print or handle as needed
        //         cout << "Negative weight cycle detected involving node " << i << endl;
        //         return;
        //     }
        // }
    }
};

// ⏳ Time Complexity = O(n³)
// 🧠 Space Complexity =O(n²) for dist matrix
