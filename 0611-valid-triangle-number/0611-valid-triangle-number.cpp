class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        sort(nums.begin(), nums.end());

        for (int k = n - 1; k >= 2; k--) {
            if (nums[k] == 0) continue; // largest side can't be 0
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    cnt += (j - i);
                    j--;
                } else {
                    i++;
                }
            }
        }
        return cnt;
    }
};
