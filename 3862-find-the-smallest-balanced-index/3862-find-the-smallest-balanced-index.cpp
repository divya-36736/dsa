class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        long long lsum = 0;
        for(int x : nums) lsum += x;

        long long rpro = 1;
        for(int i = n-1; i>=0; i--){
            lsum -= nums[i];
            if(lsum == rpro) return i;
            if(rpro > lsum/nums[i]) break;

            rpro *= nums[i];
        }
        return -1;
    }
};