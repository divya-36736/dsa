class Solution {
public:
    void help(int i, vector<int>&nums, vector<int>&set, vector<vector<int>>&ans){
        if(i >= nums.size()){
            ans.push_back(set);
            return;
        };

        set.push_back(nums[i]);

        help(i+1, nums, set, ans);
        set.pop_back();

        help(i+1, nums, set, ans);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>set;
        help(0, nums,set, ans);
        return ans;
    }
};