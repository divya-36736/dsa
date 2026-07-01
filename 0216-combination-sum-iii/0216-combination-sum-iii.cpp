class Solution {
public:

    void solve(int n,
               int i,
               int k,
               vector<vector<int>>& ans,
               vector<int>& ds){

        if(ds.size()==k){

            if(n==0)
                ans.push_back(ds);

            return;
        }

        for(int j=i;j<=9;j++){

            if(j>n)
                break;

            ds.push_back(j);

            solve(n-j,j+1,k,ans,ds);

            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> ans;
        vector<int> ds;

        solve(n,1,k,ans,ds);

        return ans;
    }
};