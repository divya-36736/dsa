class Solution {
public:
    void subs(int i, vector<int>& nums, vector<vector<int>>&ans, vector<int>ds){
        if(i==nums.size()){
            
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        subs(i+1, nums, ans, ds);
        ds.pop_back();
        subs(i+1, nums, ans, ds);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        subs(0, nums, ans, ds);
        return ans;
    }
};