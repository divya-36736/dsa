class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                bool isPeak = true;

                // Up
                if (i > 0 && mat[i][j] <= mat[i - 1][j])
                    isPeak = false;

                // Down
                if (i < m - 1 && mat[i][j] <= mat[i + 1][j])
                    isPeak = false;

                // Left
                if (j > 0 && mat[i][j] <= mat[i][j - 1])
                    isPeak = false;

                // Right
                if (j < n - 1 && mat[i][j] <= mat[i][j + 1])
                    isPeak = false;

                if (isPeak)
                    return {i, j};
            }
        }

        return {-1, -1};
    }
};