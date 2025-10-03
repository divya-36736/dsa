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

        if (z1 > 0 && z2 > 0) {
            return max(sum1 + z1, sum2 + z2);
        }
        else if (z1 > 0) {
            return (sum1 + z1 <= sum2 ? sum2 : -1);
        }
        else if (z2 > 0) {
            return (sum2 + z2 <= sum1 ? sum1 : -1);
        }
        else {
            return (sum1 == sum2 ? sum1 : -1);
        }
    }
};
