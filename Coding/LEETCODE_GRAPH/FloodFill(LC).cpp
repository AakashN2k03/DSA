// LEETCODE: 733. Flood Fill ( DFS )

class Solution {
public:
     void dfs(int row,int col,int drow[], int dcol[],vector<vector<int>>& image,vector<vector<int>>& ans,int initial_color,int color)
      {int n=image.size();
       int m=image[0].size();

        ans[row][col]=color;
        for(int i=0;i<4;i++) // four directions
        {
            int neighbour_row=row+drow[i];
            int neighbour_col=col+dcol[i];
            
            if(neighbour_row>=0 && neighbour_row<n && neighbour_col>=0 && neighbour_col<m &&
            image[neighbour_row][neighbour_col]==initial_color && ans[neighbour_row][neighbour_col]!=color)
            {
                dfs(neighbour_row,neighbour_col,drow,dcol,image,ans,initial_color,color);

            }

        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial_color=image[sr][sc];
        vector<vector<int>> ans=image;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        dfs(sr,sc,drow,dcol,image,ans,initial_color,color);
        return ans;
        
    }
};

// TIME AND SPACE COMPLEXITY : 0( N * M)
