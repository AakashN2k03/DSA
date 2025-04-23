// LEETCODE: 787. Cheapest Flights Within K Stops ( BFS)

// WHY DIJKSTRA WON'T WORK -> SEE STRIVER

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adjls(n);
        for(auto flight:flights)
        {
            adjls[flight[0]].push_back({flight[1],flight[2]});
        }
        queue<pair<int,pair<int,int>>> qu; // STOPS , NODE , COST
        qu.push({0,{src,0}});

        vector<int>distance(n,INT_MAX);

        while(!qu.empty())
        {
        int stops=qu.front().first;
        int node=qu.front().second.first;
        int cost=qu.front().second.second;
        qu.pop();

        if(stops>k) continue;
        for(auto it:adjls[node])
        {
            int adjnode=it.first;
            int edge_weight=it.second;
            if(cost+edge_weight < distance[adjnode] && stops<=k)
            {
                distance[adjnode]=cost+edge_weight;
                qu.push({stops+1,{adjnode,distance[adjnode]}});
            }
        }
        }
        if(distance[dst]==INT_MAX) return -1;
        return distance[dst];
        
    }
};

// Time Complexity: O(E) -> (only edges)
// Space Complexity: O(n + E) (Loop through all E flights)
