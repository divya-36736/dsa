class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int st = 0;
        int end = n - 1;

        while (st < end) {
            int mid = st + (end - st) / 2;

            if (mid % 2 == 1) mid--;

            if (nums[mid] == nums[mid + 1]) {
                st = mid + 2;   
            } else {
                end = mid;     
            }
        }
        return nums[st];
    }
};
