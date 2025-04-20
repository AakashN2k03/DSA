// GFG: Course Schedule (KANNS'S ALGORITHM / BFS )

// NOTE : SAME PROBLEM AS PREREQUISITE TASK BUT A SLIGHT FLIP IN adjls is  NEEDED (adjls[v].push_back(u))

class Solution {
  public:
    vector<int> findOrder(int N, vector<vector<int>> prerequisites) {
         vector<int> indegree(N);
        vector<vector<int>> adjls(N);
        
        for (auto it : prerequisites) {
           int u=it[0];
           int v=it[1];
           adjls[v].push_back(u);  // eg {0, 1}, since task 0 depends on task 1, hence the edge should be 1 -> 0
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
        vector<int>ans;
        
        int counter = 0;
        while (!qu.empty()) {
            int node = qu.front();
            qu.pop();
            counter++;
           ans.push_back(node);
            
            for (auto adjnode : adjls[node]) {
                indegree[adjnode]--;
                if (indegree[adjnode] == 0) qu.push(adjnode);
            }
        }
        
        if(counter==N) return ans;
        return {};
        
    }
};
// ✅ Time Complexity: O(V + E)
// ✅ Space Complexity: O(N)
