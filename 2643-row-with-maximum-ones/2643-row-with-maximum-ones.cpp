class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();//column
        int mini = INT_MIN;
        int idx = 0;
        for(int i = 0; i<n; i++){
            int cnt = 0;
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 1){
                    cnt++;
                }
            }
            if(mini < cnt){
                mini = cnt;
                idx = i;
            }
        }
        return {idx, mini};
    }
};