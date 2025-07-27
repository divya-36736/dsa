class Solution {
public:
    void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& vis){
        vis[x][y] = 1;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};

        int  n = grid.size();
        int m = grid[0].size();


        for(int i = 0; i<4; i++){
            int nx = x+ delrow[i];
            int ny = y+ delcol[i];

            if(nx<0|| ny<0|| nx>=n|| ny>=m|| vis[nx][ny] || grid[nx][ny] != 1) continue;

            vis[nx][ny] = 1;
            dfs(nx, ny, grid, vis);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int  n = grid.size();
        int m = grid[0].size();
        
        int cnt = 0;
        vector<vector<int>>vis(n, vector<int>(m, 0));

        //for checking at boundary
        for(int i = 0; i<m; i++){
            if(!vis[0][i] && grid[0][i] == 1){
                dfs(0, i, grid, vis);
            }

            if(!vis[n-1][i] && grid[n-1][i] == 1){
                dfs(n-1, i, grid, vis);
            }
        }
        for(int j = 0; j<n; j++){
            if(!vis[j][0] && grid[j][0] == 1){
                dfs(j ,0, grid, vis);
            }
            if(!vis[j][m-1] && grid[j][m-1] == 1){
                dfs(j, m-1, grid, vis);
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if( !vis[i][j] && grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};