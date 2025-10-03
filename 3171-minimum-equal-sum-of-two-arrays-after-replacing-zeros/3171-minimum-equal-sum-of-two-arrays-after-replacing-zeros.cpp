class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int z1 = 0, z2 = 0;

        for (int x : nums1) {
            if (x == 0) z1++;
            sum1 += x;
        }
        for (int x : nums2) {
            if (x == 0) z2++;
            sum2 += x;
        }

        long long minSum1 = sum1 + z1; // replace zeros with 1
        long long minSum2 = sum2 + z2;

        if (z1 > 0 && z2 > 0) {
            return max(minSum1, minSum2);  // always possible
        }
        else if (z1 > 0) {
            return (minSum1 <= sum2 ? sum2 : -1);
        }
        else if (z2 > 0) {
            return (minSum2 <= sum1 ? sum1 : -1);
        }
        else {
            return (sum1 == sum2 ? sum1 : -1);
        }
    }
};
