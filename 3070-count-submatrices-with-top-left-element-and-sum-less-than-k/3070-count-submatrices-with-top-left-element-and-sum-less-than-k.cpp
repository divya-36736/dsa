class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int c = grid[0].size();

        int brcol = c;
        int cnt = 0;

        if (grid[0][0] > k) return 0;
        cnt++;

        
        for (int i = 1; i < c; i++) {
            grid[0][i] += grid[0][i - 1];  

            if (grid[0][i] > k) {
                brcol = i;
                break;
            }
            cnt++;
        }

       
        for (int i = 1; i < n; i++) {

            grid[i][0] += grid[i - 1][0];

            if (grid[i][0] > k) break;
            cnt++;

            for (int j = 1; j < brcol; j++) {

                grid[i][j] += grid[i - 1][j] 
                           + grid[i][j - 1] 
                           - grid[i - 1][j - 1];  

                if (grid[i][j] > k) {
                    brcol = j;
                    break;
                }

                cnt++;
            }
        }

        return cnt;
    }
};