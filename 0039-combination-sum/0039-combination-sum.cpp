class Solution {
public:
    void solve(int i, int target, vector<int>&candidates, vector<vector<int>>&ans, vector<int>&res){
        if(target == 0){
            ans.push_back(res);
            return;
        }
        if(i >= candidates.size()) return;

        
        if(target >= candidates[i]){
            res.push_back(candidates[i]);
            solve(i, target-candidates[i],candidates, ans, res);
            res.pop_back();
        }
       
        solve(i+1, target, candidates, ans, res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>>ans;
        vector<int>path;
        solve(0, target, candidates, ans, path);
        return ans;
    }
};