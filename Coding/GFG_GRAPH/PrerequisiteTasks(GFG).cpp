// GFG: Prerequisite Tasks ( KANN'S ALGORITHM / BFS )

// NOTE : THIS SOME IS DITTO OF BFS-DIRECTED CYCLE GRAPH PROBLEM

class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int>>& prerequisites) {
        vector<int> indegree(N);
        vector<vector<int>> adjls(N);
        
        for (auto it : prerequisites) {
            adjls[it.first].push_back(it.second);
        }
        
        for (int i = 0; i < N; i++) {
            for (auto adjnode : adjls[i]) {
                indegree[adjnode]++;
            }
        }
        
        queue<int> qu;
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) qu.push(i);
        }
        
        int counter = 0;
        while (!qu.empty()) {
            int node = qu.front();
            qu.pop();
            counter++;
            
            for (auto adjnode : adjls[node]) {
                indegree[adjnode]--;
                if (indegree[adjnode] == 0) qu.push(adjnode);
            }
        }
        
        return counter == N;
    }
};
// ✅ Time Complexity: O(V + E)
// ✅ Space Complexity: O(N)
