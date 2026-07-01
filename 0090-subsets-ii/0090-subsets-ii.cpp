class Solution {
public:
    void solve(int i, vector<int>&nums, set<vector<int>>&ans, vector<int>&ds){
        if(i >= nums.size()){
            ans.insert(ds);
            return;
        }

        //take
        ds.push_back(nums[i]);
        solve(i+1, nums, ans, ds);
        ds.pop_back();
        //notake
        solve(i+1, nums, ans, ds);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>>ans;
        vector<int>ds;
        solve(0, nums, ans, ds);
        return vector<vector<int>>(ans.begin(), ans.end());
        
    }
};