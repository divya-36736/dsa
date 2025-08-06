class Solution {
public:
    int mark = -1e7;
    //mark row and mark col -1
    void markRow(vector<vector<int>>& matrix, int n, int m, int i){
        //row fix col ko -1
        for(int j= 0; j<m; j++){
            if (matrix[i][j] != 0) {
                matrix[i][j] = mark;
        }
        }
    }
    void markcol(vector<vector<int>>& matrix, int n, int m, int j){
        //col fix row ko -1
        for(int i = 0; i<n; i++){
            if (matrix[i][j] != 0) {
                matrix[i][j] = mark;
        }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i= 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == 0){
                    markRow(matrix, n, m, i);
                    markcol(matrix, n, m, j);
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == mark){
                    matrix[i][j] = 0;
            }
            }
        }
    }
};