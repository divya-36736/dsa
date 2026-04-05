class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            // even
            if (i % 2 == 0) {
                for (int j = 0; j < m; j += 2) {
                    res.push_back(grid[i][j]);
                }
            }
            // odd
            else {
                if (m % 2 == 0) {
                    for (int j = m - 1; j >= 0; j -= 2) {
                        res.push_back(grid[i][j]);
                    }
                }
                else{
                    //odd
                    for(int j = m - 2; j>=0; j -= 2){
                        res.push_back(grid[i][j]);
                    }
                }
            }
        }
        return res;
    }
};