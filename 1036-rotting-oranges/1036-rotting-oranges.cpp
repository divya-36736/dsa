class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //bfs travesing
        int n = grid.size();
        int m = grid[0].size();
        //visit
        vector<vector<int>>vis(n , vector<int>(m,0));
        queue<pair<int, int>>q;

        int fresh = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                    vis[i][j] = 1;
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        int time = -1;
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        while(!q.empty()){
            int size = q.size();
            time++;
            for(int k = 0; k<size; k++){
                auto [x,y] = q.front();
                q.pop();
                for(int dir = 0; dir<4; dir++){
                    int nx = x+dx[dir];
                    int ny = y+dy[dir];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny] == 1){
                        vis[nx][ny] = 1;
                        grid[nx][ny] =1;
                        q.push({nx, ny});
                        fresh--;
                    }
                }
            }
        }
        if(fresh>0) return -1;
        return max(0, time);
    }
};