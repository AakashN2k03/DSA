// LEETCODE: 1192. Critical Connections in a Network (BRIGE PROBLEM) (TARJANS'S ALGORITHM) 

//NOTE:
// tin[node] → Time when the node was first visited.
// low[node] → min lowest time insertion of all adjacent nodes apart from parent node

// DRY RUN THIS CODE 

class Solution {
public:
int timer=1;
void dfs(int node,int parent,vector<int>&vis,vector<vector<int>>&adj,vector<vector<int>>&bridges,vector<int>&low,vector<int>&tin)
{
    vis[node]=1;
    low[node]=tin[node]=timer;
    timer++;
    for(auto it:adj[node])
    {
        if(it==parent) continue;
        if(!vis[it])
        {
            dfs(it,node,vis,adj,bridges,low,tin);
            low[node]=min(low[node],low[it]);
            if(low[it]>tin[node])
            {
                bridges.push_back({it,node});
            }
        }
        else{
            low[node]=min(low[node],low[it]);
        }
    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto connection:connections)
        {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);

        }
        vector<int>vis(n,0);
        vector<vector<int>>bridges;
        vector<int>tin(n);
        vector<int>low(n);

        dfs(0,-1,vis,adj,bridges,low,tin);
        return bridges;
        
    }
};

// Time Complexity=O(V+2E) => O(V+E)
// Space Complexity=O(V+2E) +O(3N) => O(V+E)
