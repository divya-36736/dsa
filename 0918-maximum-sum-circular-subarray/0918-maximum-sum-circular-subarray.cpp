class Solution {
public:
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        //max  = tot - min
        int tot = 0;
        int maxsum = nums[0];
        int currmax = 0;
        int minsum = nums[0];
        int currmin = 0;
        for(int x: nums){
            currmax = max(currmax+x, x);
            maxsum = max(maxsum, currmax);

            currmin = min(currmin+x, x);
            minsum = min(minsum, currmin);

            tot += x;
        }
        //all num are negative
        if(maxsum<0) return maxsum;
        return max(maxsum, tot-minsum);
    }
};