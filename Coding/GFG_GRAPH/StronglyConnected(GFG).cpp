// GFG: Strongly Connected (KOSARAJU'S ALGORITHM)

// Kosaraju's Algorithm is a method to find Strongly Connected Components (SCCs) in a directed graph.
// SCCs only need a directed graph — it doesn't matter if it is weighted or unweighted.


// NOTE:Three Main Intuitions to solve the problem:
// 1.Order nodes by finish time (using 1st DFS): Nodes that finish later have stronger chances to be starting points of SCCs.
// 2.Reverse all edges (Transpose graph):Reversing edges allows us to move within a SCC easily in second traversal.
// 3.Do DFS in the stack order:Popping nodes from stack ensures we visit all nodes in a SCC together and can count them correctly.


class Solution {
  public:
    void dfs(int node,vector<int>&vis,vector<vector<int>>&adj, stack<int>&st)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it,vis,adj,st);
            }
        }
        st.push(node);
    }
    void dfs_SCC_count(int node,vector<int>&vis,vector<vector<int>>&adjls, stack<int>&st)
    {
         vis[node]=1;
        for(auto it:adjls[node])
        {
            if(!vis[it])
            {
                dfs_SCC_count(it,vis,adjls,st);
            }
        }
    
    }
    
    int kosaraju(vector<vector<int>> &adj) {
        
        int V=adj.size();
        vector<int> vis(V,0);
        stack<int>st;
        // push the nodes respect to their finishing time 
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,adj,st);
            }
        }
        
        // reverse the edges in strongly connected graph (SCC)
        
        vector<vector<int>>adjls(V);
        for(int i=0;i<V;i++)
        {   vis[i]=0;  // resue the visited array
            for(auto it:adj[i])
            {
                adjls[it].push_back(i);
            }
        }
        
        // THEN use DFS
        int scc=0;
        while(!st.empty())
        {
             int node=st.top();
             st.pop();
            if(!vis[node])
            {  scc++;
                dfs_SCC_count(node,vis,adjls,st);
            }
        }
        return scc;
    }
};

// Time Complexity:
// First DFS to fill stack: O(V + E)
// Reversing the graph: O(V + E)
// Second DFS traversal: O(V + E)
// ➔ So Total = O(V + E)

// Space Complexity:
// Stack for DFS recursion: O(V) (in worst case, chain graph)
// vis array: O(V)
// adjls reversed graph: O(V + E)
// ➔ So Total = O(V + E)
