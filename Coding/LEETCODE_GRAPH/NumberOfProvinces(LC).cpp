// LEETCODE: 547. Number of Provinces (DFS,RECURSION)
class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adjls) {
        vis[node] = 1;
        for (auto it : adjls[node]) {
            if (!vis[it]) {
                dfs(it, vis, adjls);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        vector<vector<int>> adjls(size);  

        // CONVERSION FROM ADJ MATRIX TO LIST
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {  
                if (isConnected[i][j] == 1 && i != j) {   // YOU CAN REMOVE THIS i != j STILL WORKS , BUT PROVINCE DOES NOT CALCULATE SELF LOOP COUNT
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);  
                }
            }
        }

        vector<int> vis(size, 0);
        int counter = 0;
        for (int i = 0; i < size; i++) {  // ✅ Start from 0
            if (vis[i] == 0) {
                counter++;
                dfs(i, vis, adjls);
            }
        }
        return counter;
    }
};
// TIME COMPLEXITY: O(N) + O(V+E) // HERE O(N) DUE TO UNCONNECTED GRAPHS 
// SPACE COMPLEXITY: O(N)
