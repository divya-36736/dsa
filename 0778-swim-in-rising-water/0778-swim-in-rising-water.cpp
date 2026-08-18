class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        vector<vector<bool>> vis(n, vector<bool>(n, false));

        pq.push({grid[0][0], {0, 0}});

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int time = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if (vis[r][c]) continue;
            vis[r][c] = true;

            if (r == n - 1 && c == n - 1)
                return time;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nc >= 0 && nr < n && nc < n && !vis[nr][nc]) {
                    int newTime = max(time, grid[nr][nc]);
                    pq.push({newTime, {nr, nc}});
                }
            }
        }

        return -1;
    }
};