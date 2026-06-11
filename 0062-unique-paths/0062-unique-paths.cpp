class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>prev(n, 0); //it represent the prev row
        prev[0] = 1;

        for (int i = 0; i < m; i++) {
            vector<int>temp(n, 0); // temp will store the current row's results
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0){
                    temp[j] = 1;
                    continue;
                } 
                
                int up = 0, left = 0;
                if (i > 0) up = prev[j]; //what is dp[i-1] prev and what is dp[i] is curr
                if (j > 0) left = temp[j - 1];
                temp[j] = up + left;
               
            }
            prev = temp; //this do after one row complete
        }
        return prev[n - 1];
    }
};