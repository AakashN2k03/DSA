// LEETCODE: 1631. Path With Minimum Effort (DIJKSTRA ALGORITHM WITH PRIORITY QUEUE)

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>distance(n,vector<int>(m,INT_MAX));
        distance[0][0]=0;
            // Dijkstra's initialization
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}}); // (diff, {row, col})

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        while(!pq.empty())
        {
            int diff=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();

            if(row==n-1 && col==m-1) return diff;

            for(int i=0;i<4;i++)
            {
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                {
                    int effort=max(abs(heights[nrow][ncol] - heights[row][col]),diff);
                    if(effort<distance[nrow][ncol])
                    {
                        distance[nrow][ncol]=effort;
                        pq.push({effort,{nrow,ncol}});
                    }
                }

            }
        }

      return -1;  
    }
};

// Time Complexity = O(E.LOG V) =>  O((N × M * 4) × log(N × M))  // 4 -  no of directions
// Space Complexity = O(N × M)
