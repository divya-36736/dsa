class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, vector<int>(n, 0));

        // Loop over all queries
        for (int i = 0; i < queries.size(); i++) {
            int r1 = queries[i][0];
            int c1 = queries[i][1];
            int r2 = queries[i][2];
            int c2 = queries[i][3];

            for (int r = r1; r <= r2; r++) {
                for (int c = c1; c <= c2; c++) {
                    mat[r][c] += 1;
                }
            }
        }

        return mat;
    }
};
