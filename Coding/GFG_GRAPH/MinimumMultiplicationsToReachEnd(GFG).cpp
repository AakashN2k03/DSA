// GFG: Minimum Multiplications to reach End (DIJKSTRA ALGORITHM)
 

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
      if (start == end) return 0;

       queue<pair<int,int>> qu;
       qu.push({start,0});
       
       vector<int>distance(100000,1e9); // NODE ARE FROM 0 - 99999
       distance[start]=0;
       int mod=100000;
       while(!qu.empty())
       {
           int node=qu.front().first;
           int steps=qu.front().second;
           qu.pop();
           
           for(auto it:arr)
           {
               int num=(it*node)%mod;
                if(steps+1 < distance[num])
               {   
                    distance[num]=steps+1;
                    if(num==end) return steps+1;
                    qu.push({num,steps+1});
               }
               
              
           }
       }
       return -1;
    }
};

 // Time Complexity:O(N * 100000)
 // space Complexity:O(N + 100000)
​
