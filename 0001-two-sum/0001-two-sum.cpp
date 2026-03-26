class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int>ExistIdx;
        for(int i = 0; i<n; i++){
            int num = nums[i];
            if(ExistIdx.find(target - num) != ExistIdx.end()){
                return {i, ExistIdx[target-num]};
            }
            ExistIdx[nums[i]] = i;
        }
        return {};
    }
};