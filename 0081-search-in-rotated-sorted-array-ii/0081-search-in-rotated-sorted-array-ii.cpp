class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        //bool ans  =  false;
        // for(int i = 0; i<n; i++){
        //     if(nums[i] == target){
        //         ans = true;
        //     }
        // }
        // return ans;

        int st = 0;
        int end = n-1;
        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] == target) return true;

            // Handle duplicates
            if (nums[st] == nums[mid] && nums[mid] == nums[end]) {
                st++;
                end--;
            }
            // Left half is sorted
            else if (nums[st] <= nums[mid]) {
                if (nums[st] <= target && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[end]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};