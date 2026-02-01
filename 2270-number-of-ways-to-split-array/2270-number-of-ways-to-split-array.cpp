class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long>prefix(n, 0);
        prefix[0] = nums[0];

        for(int i = 1; i<n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        long long total = prefix[n-1];
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