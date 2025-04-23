// GFG: Shortest Path in Weighted undirected graph (DIJKSTRA)

// NOTE : INSTEAD OF RETURNING THE VALUES OF NODE.. RETURN THE ACTUAL PATH. EG 1->2->3->4

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>>>adjls(n+1);
        for(auto edge:edges)
        {
            adjls[edge[0]].push_back({edge[1],edge[2]});
            adjls[edge[1]].push_back({edge[0],edge[2]});
        }
        
        vector<int>distance(n+1,INT_MAX);
        vector<int>parent(n+1);
        
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0,1});
        distance[1]=0;
        
        while(!pq.empty())
        {
            auto it=pq.top();
            int node=it.second;
            int wt=it.first;
            pq.pop();
            
            for(auto it:adjls[node])
            {
                int adjnode=it.first;
                int edge_weight=it.second;
                
                if(distance[node]+edge_weight<distance[adjnode])
                {
                    distance[adjnode]=distance[node]+edge_weight;
                    parent[adjnode]=node;
                    pq.push({distance[adjnode],adjnode});
                }
            }
        }
        
        if(distance[n]==INT_MAX) return {-1};
        
        vector<int>path;
        int end_node=n;
        while(parent[end_node]!=end_node)
        {  
            path.push_back(end_node);
            end_node=parent[end_node];
        }
        path.push_back(1); // src
        
        reverse(path.begin(),path.end());
        path.insert(path.begin(), distance[n]);// This line is just for output format in gfg

      
       return path;
       
        
    }
};

// Time 	Complexity:O(E ⋅ log V) + O(N)  -> O(N) for iterating in path vector
// Space Complexity:	O(E+V)
