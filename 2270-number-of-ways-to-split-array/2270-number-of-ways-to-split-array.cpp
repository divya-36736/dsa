class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();

        long long total = 0;
        for(int num : nums){
            total += num;
        }

        long long leftsum = 0;
        int cnt = 0;

        for(int i = 0; i<n-1; i++){
            leftsum += nums[i];
            long long rightsum = total - leftsum;
            if(leftsum >= rightsum) cnt++;
        }
        return cnt;
    }
};