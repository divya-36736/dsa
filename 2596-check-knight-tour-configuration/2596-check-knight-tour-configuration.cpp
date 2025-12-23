class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();

        // knight must start at (0,0)
        if (grid[0][0] != 0) return false;

        // store position of each number
        vector<pair<int,int>> pos(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pos[grid[i][j]] = {i, j};
            }
        }

        // check all consecutive moves
        for (int k = 0; k < n * n - 1; k++) {
            int r1 = pos[k].first;
            int c1 = pos[k].second;
            int r2 = pos[k + 1].first;
            int c2 = pos[k + 1].second;

            int dr = abs(r1 - r2);
            int dc = abs(c1 - c2);

            // valid knight move check
            if (!((dr == 2 && dc == 1) || (dr == 1 && dc == 2))) {
                return false;
            }
        }

        return true;
    }
};
