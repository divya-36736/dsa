class Solution {
public:

    void getAllsubsets(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &allsubsets){
        if(i == nums.size()){
            allsubsets.push_back({ans});
            return;
        }

        //include
        ans.push_back(nums[i]);
        getAllsubsets(nums, ans, i+1, allsubsets);

        //backtracking
        ans.pop_back();
        getAllsubsets(nums, ans, i+1, allsubsets);

    }




    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> allsubsets;
      vector<int> ans;
      getAllsubsets(nums, ans, 0, allsubsets);
      return allsubsets;
    }
};