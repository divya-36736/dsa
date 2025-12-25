class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int c1 = n / 2;
        int c2 = m / 2;

        unordered_map<int, int> mp1; // Y cells
        unordered_map<int, int> mp2; // non-Y cells

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // left diagonal, right diagonal, and center column
                if ((i <= c1 && (j == i || j == m - 1 - i)) ||
                    (i > c1 && j == c2)) {
                    mp1[grid[i][j]]++;
                } else {
                    mp2[grid[i][j]]++;
                }
            }
        }

        int ans = INT_MAX;

        // try all combinations of colors
        for (int y = 0; y < 3; y++) {
            for (int ny = 0; ny < 3; ny++) {
                if (y == ny) continue;

                int ops = 0;

                for (int i = 0; i < 3; i++) {
                    if (i != y) ops += mp1[i];
                    if (i != ny) ops += mp2[i];
                }

                ans = min(ans, ops);
            }
        }

        return ans;
    }
};
