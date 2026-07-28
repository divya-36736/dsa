class Solution {
public:
    int maxvalfind(vector<vector<int>>&mat, int col){
        int n = mat.size();
        int maxval = INT_MIN;
        int idx = -1;
        for(int i = 0; i<n; i++){
            if(maxval < mat[i][col]){
                maxval = mat[i][col];
                idx = i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0;
        int high = m-1;

        while(low<=high){
            int mid = (low+high)/2;

            int row = maxvalfind(mat, mid);

            int left = mid-1>=0?mat[row][mid-1]:INT_MIN;
            int right = mid+1<m?mat[row][mid+1]:INT_MIN;

            if(mat[row][mid] > left && mat[row][mid] > right){
                return {row, mid};
            }
            else if(left > mat[row][mid]){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return {-1, -1};
    }
};