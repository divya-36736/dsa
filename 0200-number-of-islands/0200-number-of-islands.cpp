class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>&grid, vector<vector<int>>&visited){
        visited[i][j] = 1;

        int n = grid.size();
        int m = grid[0].size();

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, -1, 0, 1};

        for(int dir= 0; dir<4; dir++){
            int nx = i + dx[dir];
            int ny = j + dy[dir];

            if(nx<0 || nx>=n || ny<0 || ny>=m || visited[nx][ny] || grid[nx][ny] == '0') continue;

            visited[nx][ny] = 1;
            dfs(nx, ny, grid, visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>>visited(n, vector<int>(m, 0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    dfs(i, j, grid, visited);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};