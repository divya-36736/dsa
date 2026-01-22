class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
          int max=0,ansi=0,ansj=0;
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            if(mat[i][j]>max){
                max=mat[i][j];
                ansi=i;
                ansj=j;
            }
        }
    }
    return {ansi,ansj};  
    }
};