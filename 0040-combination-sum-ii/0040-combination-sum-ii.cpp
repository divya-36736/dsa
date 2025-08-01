class Solution {
public:
    void subs(int i, int target, vector<vector<int>>&ans, vector<int>&ds, vector<int>&candidates){
        if(target == 0){
            ans.push_back(ds);
        }
        for(int j = i; j<candidates.size(); j++){
            if(j>i && candidates[j] == candidates[j-1]) continue; //if dublicate skip
            if(candidates[j]>target) break; //if target se badi value hogi toh bresk kr jange
            ds.push_back(candidates[j]);
            subs(j+1, target-candidates[j], ans, ds, candidates); //every value use only once
            ds.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        subs(0, target, ans, ds, candidates);
        return ans;
    }
};