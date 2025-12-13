class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size();
        long long positive = 0, negative = 0;
        if(nums1 == nums2) return 0;
        for (int i = 0; i < n; i++) {
            long long diff = nums2[i] - nums1[i];
            //if k == 0 hua toh operation possible nhi hai
            if (k == 0) {
                if (diff != 0) return -1;
                continue;
            }
            //if diff divisible by k hua toh all operation possible hai
            if (diff % k != 0) return -1;
            //pos and neg match hona chahiye kyuki +-k hoga;
            if (diff > 0) positive += diff;
            else negative += diff;
        }

        if (positive + negative != 0) return -1;

        return positive / k;
    }
};
