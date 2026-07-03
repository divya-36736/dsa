class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>>q;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, -1, 0, 1};

        //cal to distance from the thief to all node
        while(!q.empty()){
            auto it = q.front();
            int x = it.first;
            int y = it.second;
            q.pop();

            for(int dir = 0; dir<4; dir++){
                int nx = x+dx[dir];
                int ny = y+dy[dir];

                if(nx>=0 && ny>=0 && nx<n && ny<m && dist[nx][ny]>dist[x][y]+1){
                    dist[nx][ny] = dist[x][y]+1;
                    q.push({nx, ny});
                }
            }
        }

        //now use max heap
        priority_queue<vector<int>>pq;
        vector<vector<int>>vis(n, vector<int>(n, 0));

        pq.push({dist[0][0], 0, 0});
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int safe = curr[0];
            int x = curr[1];
            int y = curr[2];

            if(vis[x][y]) continue;
            vis[x][y] = 1;

            if(x == n-1 && y == m-1) return safe;

            for(int dir = 0; dir<4; dir++){
                int nx = x+dx[dir];
                int ny = y+dy[dir];

                if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny]){
                    int newsafe = min(safe, dist[nx][ny]);
                    pq.push({newsafe, nx, ny});
                }
            }
        }
        return 0;
    }
};