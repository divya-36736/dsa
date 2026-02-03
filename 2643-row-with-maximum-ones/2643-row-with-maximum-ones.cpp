class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans(2,-1);

        for(int i = 0; i<mat.size(); i++){
            int count = 0;
            for(int j = 0; j<mat[i].size(); j++){
                if(mat[i][j] == 1)
                count++;
            }
            if(count > ans[1]){
                ans[1] = count;
                ans[0] = i;
            }
        }
        return ans;
    }
};