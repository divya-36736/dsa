class Solution {
public:
    void solve(int idx, vector<vector<int>>&ans, vector<int>&nums){
        int n = nums.size();
        if(idx == nums.size()){
            ans.push_back({nums});
            return;
        }

        for(int i = idx; i<n; i++){
            swap(nums[idx], nums[i]);//swap
            solve(idx+1, ans, nums);//explore
            swap(nums[i], nums[idx]);//undo
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        solve(0, ans, nums);
        return ans;
    }
};