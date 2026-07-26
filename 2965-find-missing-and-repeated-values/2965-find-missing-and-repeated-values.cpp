class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        long long tot = 1LL * n * n;

        long long sn = tot * (tot + 1) / 2;
        long long s2n = tot * (tot + 1) * (2 * tot + 1) / 6;

        long long s = 0, s2 = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                s += grid[i][j];
                s2 += 1LL * grid[i][j] * grid[i][j];
            }
        }

        long long val1 = s - sn;       
        long long val2 = s2 - s2n;     

        val2 = val2 / val1;            

        long long x = (val1 + val2) / 2;
        long long y = x - val1;

        return {(int)x, (int)y};
    }
};