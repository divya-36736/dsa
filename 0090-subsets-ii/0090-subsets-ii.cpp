class Solution {
public:
    void subsetH(int i, vector<vector<int>>&ans, vector<int>&ds, vector<int>& nums){  
        //brute force approach
        // if(i == nums.size()){
        //     ans.insert(ds);
        //     return;
        // }


        // //take
        // ds.push_back(nums[i]);
        // subsetH(i+1, ans, ds, nums);
        // //not take
        // ds.pop_back();
        // subsetH(i+1, ans, ds, nums);


        //optimal approach
        ans.push_back(ds);
        for(int j = i; j<nums.size(); j++){
            if(j != i && nums[j] == nums[j-1]) continue; //dublicate skip
            ds.push_back(nums[j]);
            subsetH(j+1, ans, ds, nums);
            ds.pop_back();
        }
       
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // set<vector<int>>ans;
        // vector<vector<int>>res;
        // vector<int>ds;
        // subsetH(0, ans,ds, nums);
        // for(auto it = ans.begin(); it != ans.end(); it++){
        //     res.push_back(*it);
        // }
        // return res;
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int>ds;
        subsetH(0, ans, ds, nums);
        return ans;
    }
};