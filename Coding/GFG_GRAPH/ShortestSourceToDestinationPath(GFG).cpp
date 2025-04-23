// GFG: Shortest Source to Destination Path (Shortest Distance in a Binary Maze)  (BFS)

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
       vector<vector<int>>distance_weight(N,vector<int>(M,INT_MAX));
       queue<pair<int,pair<int,int>>>qu; // DISTANCE, ROW ,COL
       qu.push({0,{0,0}});
       
       int drow[]={-1,0,1,0};
       int dcol[]={0,1,0,-1};
       
       distance_weight[0][0]=0; // src 
        if (A[0][0] == 0) return -1; // EDGE CASE:1 Cannot start from blocked cell 
       if(X==0 && Y==0) return 0 ; // EDGE CASE :2 src and destination same
       while(!qu.empty())
       {
           int distance=qu.front().first;
           int row=qu.front().second.first;
           int col=qu.front().second.second;
           qu.pop();
           
           for(int i=0;i<4;i++)
           {
               int nrow=row+drow[i];
               int ncol=col+dcol[i];
               
              if (nrow == X && ncol == Y && A[nrow][ncol] == 1) return distance + 1; //EDGE CASE :3 (A[nrow][ncol] == 1)
               
               if(nrow>=0 && nrow<N && ncol>=0 && ncol<M && A[nrow][ncol]==1 && distance + 1 < distance_weight[nrow][ncol] )
               {
                   distance_weight[nrow][ncol]=distance+1;
                   qu.push({distance+1,{nrow,ncol}});
                   
               }
           }
       }
       return -1;
    }
};
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)
