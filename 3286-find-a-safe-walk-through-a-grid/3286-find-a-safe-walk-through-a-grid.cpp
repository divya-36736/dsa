class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int n = grid.size();
        int m = grid[0].size();

        int startHealth = health - grid[0][0];

        if(startHealth <= 0)
            return false;

        vector<vector<int>> best(n, vector<int>(m, -1));

        queue<vector<int>> q;
        q.push({0, 0, startHealth});
        best[0][0] = startHealth;

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, -1, 0, 1};

        while(!q.empty()) {

            auto it = q.front();
            q.pop();

            int i = it[0];
            int j = it[1];
            int h = it[2];

            if(i == n-1 && j == m-1)
                return true;

            for(int k = 0; k < 4; k++) {

                int nx = i + dx[k];
                int ny = j + dy[k];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                int newHealth = h - grid[nx][ny];

                if(newHealth <= 0)
                    continue;

                if(newHealth <= best[nx][ny])
                    continue;

                best[nx][ny] = newHealth;
                q.push({nx, ny, newHealth});
            }
        }

        return false;
    }
};