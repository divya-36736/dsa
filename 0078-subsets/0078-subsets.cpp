class Solution {
public:
    void help(int i, vector<int>&nums, vector<int>&st, vector<vector<int>>&ans){
        if(i >= nums.size()){
            ans.push_back(st);
            return;
        }
        //take
        st.push_back(nums[i]);
        help(i+1, nums, st, ans);
        st.pop_back();
        //nottake
        help(i+1, nums, st, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>subset;
        help(0, nums, subset, ans);
        return ans;
    }
};