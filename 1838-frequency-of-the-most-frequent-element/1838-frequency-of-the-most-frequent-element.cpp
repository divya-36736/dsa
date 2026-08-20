class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long sum = 0;
        int left = 0;
        int res = 1;

        for(int right = 0; right<n; right++){
            sum += nums[right];
            //while cost>k, shrink window
            while((long long)nums[right]*(right-left+1)-sum > k){
                sum -= nums[left];
                left++;
            }
            res = max(res, right-left+1);
        }
        return res;
    }
};