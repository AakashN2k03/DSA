// GFG: Minimum Spanning Tree (PRIM'S ALGORITHM)

// 🌟 MST = Minimum Spanning Tree
// You are given a graph (nodes + edges with weights).
// A spanning tree is a subgraph that:
// Connects all nodes together (no node is left out).
// Has no cycles (like a tree).
// Among all possible spanning trees, the Minimum Spanning Tree (MST) is the one with the smallest total edge weight.


// 🌟 What is Prim's Algorithm?
// Prim's Algorithm is a famous algorithm to find the MST.
// How Prim's works:
// Start from any node (say, node 0).
// Always pick the smallest weight edge that connects to a new unvisited node.
// Keep adding such edges until all nodes are visited.
// It uses a priority queue (min-heap) to find the minimum edge quickly.
// 👉 In short: "Grow the MST step-by-step, always picking the cheapest available connection."

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        vector<int>vis(V,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        int sum=0;
        while(!pq.empty())
        {
            int node=pq.top().second;
            int wt=pq.top().first;
            pq.pop();
            // if node already visited
            if(vis[node]) continue;
            
            // if node  visited first time
            vis[node]=1;
            sum+=wt;
            for(auto it:adj[node])
            {
                int adjnode=it[0];
                int wt=it[1];
                pq.push({wt,adjnode});
            }
        }
        
        return sum;
    }
};

// Time Complexity = O(E LOG E ) // see Striver
// Space Complexity = O(V + E)
