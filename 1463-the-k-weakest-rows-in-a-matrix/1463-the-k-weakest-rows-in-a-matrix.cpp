class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<pair<int,int>> ans; 

        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < mat[i].size(); j++){
                if(mat[i][j] == 1) cnt++;
                else break; 
            }
            ans.push_back({cnt, i});
        }
        sort(ans.begin(), ans.end());

        vector<int> ans1;
        for(int i = 0; i < k; i++){
            ans1.push_back(ans[i].second);
        }

        return ans1;
    }
};
