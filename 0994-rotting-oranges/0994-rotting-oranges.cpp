class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        int fresh = 0;
        int minutes = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 2) {
                    q.push({i, j});
                    visited[i][j] = 1;
                }

                if(grid[i][j] == 1)
                    fresh++;
            }
        }

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, -1, 0, 1};

        
        while(!q.empty()) {

            int size = q.size();
            bool rottenThisMinute = false;

            for(int i = 0; i < size; i++) {

                auto it = q.front();
                q.pop();

                int x = it.first;
                int y = it.second;

                for(int dir = 0; dir < 4; dir++) {

                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if(nx >= 0 && ny >= 0 && nx < n && ny < m &&
                       grid[nx][ny] == 1 && !visited[nx][ny]) {

                        visited[nx][ny] = 1;
                        q.push({nx, ny});

                        fresh--;
                        rottenThisMinute = true;
                    }
                }
            }

            if(rottenThisMinute)
                minutes++;
        }

        if(fresh != 0)
            return -1;

        return minutes;
    }
};