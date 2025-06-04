class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(matrix[i][j] == target){
                    return true;
                }

            }
        }
        // int low = 0;
        // int high = n*m-1;
        // while(low <= high){
        //     int mid = low + (high-low)/2;
        //     int row = mid/n;
        //     int col = mid%n;
        //     if(matrix[row][col] == target){
        //         return true;
        //     }
        //     else if(matrix[row][col] > target){
        //         high = mid - 1;
        //     }
        //     else{
        //         low = mid + 1;
        //     }
        // }
    return false;
    }
};
    //     int row = 0;
    //     int col = n-1;
    //     while(row < m && col >= 0){
    //         if(target == matrix[row][col]){
    //             return true;
    //         }
    //         else if(target < matrix[row][col]){
    //             col--;
    //         }
    //         else{
    //             row++;
    //         }
    //     }

    //    return false;

        