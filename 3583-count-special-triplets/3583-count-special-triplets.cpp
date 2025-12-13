class Solution {
public:
    static const int mod = 1e9 + 7;

    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;

        unordered_map<int, long long> left, right;

        // fill right frequency
        for (int x : nums) {
            right[x]++;
        }

        for (int j = 0; j < n; j++) {
            right[nums[j]]--;

            int target = 2 * nums[j];

            // apply modulo safely
            cnt = (cnt + (left[target] * right[target]) % mod) % mod;

            left[nums[j]]++;
        }

        return (int)cnt;
    }
};
