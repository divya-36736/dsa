class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        if (k == 0) return nums;             // each element itself
        int windowSize = 2*k + 1;
        if (windowSize > n) return ans;      // window larger than array

        long long windowSum = 0;

        // initial window [0 .. windowSize-1]
        for (int i = 0; i < windowSize; i++) {
            windowSum += nums[i];
        }

        // center is at k
        ans[k] = windowSum / windowSize;

        // slide the window
        for (int i = windowSize; i < n; i++) {
            windowSum += nums[i];              // add new element
            windowSum -= nums[i - windowSize]; // remove oldest element
            int center = i - k;                // new center index
            ans[center] = windowSum / windowSize;
        }

        return ans;
    }
};
