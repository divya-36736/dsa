class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mpp;
        mpp[0] = 1;
        int prefixsum = 0;
        int cnt = 0;
        for(auto &num:nums){
            prefixsum += num;
            if(mpp.find(prefixsum - k) != mpp.end()){
                cnt += mpp[prefixsum-k];
            }
            mpp[prefixsum]++;
        }
        return cnt;
    }
};