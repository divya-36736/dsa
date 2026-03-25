class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int bitmask = 0;
        int maxlen = 0;
        while(r<n){
            while((bitmask & nums[r])!= 0){
                bitmask ^= nums[l];
                l++;
            }
            bitmask |= nums[r];
            maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};