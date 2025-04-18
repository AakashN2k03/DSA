// LEETCODE: 130. Surrounded Regions ( DFS )

//  STEPS:
1. FIRST FIND 'O' FROM FIRST ROW,COL AND LAST ROW, COL.
2. IF THE SELECTED VALUE HAS CONNECTION WITH OTHER 'O' USE DFS.
3. ATLAST ITERATE THROUGH ALL THE VALUES IN THE  BOARD TO FIND NOT VISITED '0'(0's NOT IN ANY BOUNDARY) AND REPLACE IT WITH 'X'
  
class Solution {
public:
   void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& board,int drow[],int dcol[],int n,int m)
   {
       vis[row][col]=1;
       for(int i=0;i<4;i++)
       {
        int nrow=row+drow[i];
        int ncol=col+dcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O')
        {
            dfs(nrow,ncol,vis,board,drow,dcol,n,m);
        }

       }
   }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};


        for(int i=0;i<m;i++) // first row , iterate through col
        {
            if(!vis[0][i] && board[0][i]=='O')
            {
                dfs(0,i,vis,board,drow,dcol,n,m);
            }
            if(!vis[n-1][i] && board[n-1][i]=='O')
            {
                dfs(n-1,i,vis,board,drow,dcol,n,m); //last row
            }
        }

         for(int j=0;j<n;j++) // first col , iterate through row
        {
            if(!vis[j][0] && board[j][0]=='O')
            {
                dfs(j,0,vis,board,drow,dcol,n,m);
            }
             if(!vis[j][m-1] && board[j][m-1]=='O') //last col
            {
                dfs(j,m-1,vis,board,drow,dcol,n,m);
            }
        }

    
 
       // iterating to check whether 'O' already visited or not
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j] && board[i][j]=='O')
            {
                board[i][j]='X';
            }
        }
       }
        
    }
};
// Time Complexity: O(N * M)
// Space Complexity: O(N * M)
