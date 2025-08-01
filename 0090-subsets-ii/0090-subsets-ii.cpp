class Solution {
public:
    void subsetH(int i, set<vector<int>>&ans, vector<int>&ds, vector<int>& nums){
        if(i == nums.size()){
            ans.insert(ds);
            return;
        }

        //take
        ds.push_back(nums[i]);
        subsetH(i+1, ans, ds, nums);
        //not take
        ds.pop_back();
        subsetH(i+1, ans, ds, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>>ans;
        vector<vector<int>>res;
        vector<int>ds;
        subsetH(0, ans,ds, nums);
        for(auto it = ans.begin(); it != ans.end(); it++){
            res.push_back(*it);
        }
        return res;

    }
};