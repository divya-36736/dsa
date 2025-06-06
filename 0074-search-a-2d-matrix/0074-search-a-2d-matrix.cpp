class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // for(int i = 0; i<matrix.size(); i++){
        //     for(int j = 0; j<matrix[i].size(); j++){
        //         if(matrix[i][j] == target){
        //             return true;
        //         }
        //     }
        // }
        // return false;
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = m*n - 1;
        while(low <= high){
            int mid = low + (high-low)/2;
            int row = mid/m; 
            int col = mid%m;
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return false;
    }
};