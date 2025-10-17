class Solution {
public:
    bool hasIncreasing(vector<int>& nums, int k) {
        int n = nums.size();
        int k1 = k - 1;
        if (k1 == 0)
            return true; // one size always true
        for (int j = k + 1; j < n; j++) {
            if (nums[j] > nums[j - 1] && nums[j - k] > nums[j - k - 1])
                k1--;
            else
                k1 = k - 1; // reset k1
            if (k1 == 0)
                return true;
        }
        return false;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        // int n = nums.size();
        // int maxk = 0;
        // for(int k = 1; k<=n/2; k++){
        //     if(hasIncreasing(nums, k)){
        //         maxk = k;
        //     }
        // }
        // return maxk;
        int low = 1, high = nums.size() / 2, ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (hasIncreasing(nums, mid)) {
                ans = mid;
                low = mid + 1; // try bigger k
            } else {
                high = mid - 1; // try smaller k
            }
        }
        return ans;
    }
};