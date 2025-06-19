class Solution {
public:

    // void getAllsubsets(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &allsubsets){
    //     if(i == nums.size()){
    //         allsubsets.push_back({ans});
    //         return;
    //     }

    //     //include
    //     ans.push_back(nums[i]);
    //     getAllsubsets(nums, ans, i+1, allsubsets);

    //     //backtracking
    //     ans.pop_back();
    //     getAllsubsets(nums, ans, i+1, allsubsets);

    // }




    vector<vector<int>> subsets(vector<int>& nums) {
    //   vector<vector<int>> allsubsets;
    //   vector<int> ans;
    //   getAllsubsets(nums, ans, 0, allsubsets);
    //   return allsubsets;

    int n = nums.size();
    int subset = 1<<n;
    vector<vector<int>>result;
    for(int mask =0; mask<subset; ++mask){
        vector<int> res;
            for(int i = 0; i < n; ++i){
                if(mask & (1 << i)){ 
                    res.push_back(nums[i]);
                }
            }
            result.push_back(res);
        }

        return result;
    
    }
};