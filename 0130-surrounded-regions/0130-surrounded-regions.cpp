class Solution {
public:
    void dfs(int x,  int y ,vector<vector<char>>& board, vector<vector<int>>& vis){
        vis[x][y] = 1;
         int delrow[] = {-1, 0, 1, 0};
         int delcol[] = {0, -1, 0, 1};
         int n = board.size();
         int m = board[0].size();

         for(int i = 0; i<4; i++){
            int nx = x+delrow[i];
            int ny = y+delcol[i];

            if(nx<0 || ny<0 || nx>=n || ny>=m || vis[nx][ny] || board[nx][ny]!='O') continue;
            vis[nx][ny] = 1;
            dfs(nx, ny, board, vis);
         }
    }


    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        //visited matrix with 0 values
        vector<vector<int>>vis(n, vector<int>(m , 0));

        // 0 at boundaries 
        //1st check in row
        for(int i = 0; i<m; i++){
            if(!vis[0][i] && board[0][i] == 'O'){
                dfs(0, i, board, vis);
            }

            if(!vis[n-1][i] && board[n-1][i] == 'O'){
                dfs(n-1, i, board, vis);
            }
        }
        for(int j = 0; j<n; j++){
            if(!vis[j][0] && board[j][0] == 'O'){
                dfs(j ,0, board, vis);
            }
            if(!vis[j][m-1] && board[j][m-1] == 'O'){
                dfs(j, m-1, board, vis);
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if( !vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};