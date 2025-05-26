class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0;
        int end = n-1;
        int ans = n;
        while(st<=end){
            int mid = st + (end-st)/2;
            if(nums[mid] == target){
                ans = mid;
                break;
            }
            else if(nums[mid] < target){
                ans = mid + 1;
                st = mid + 1;
            }
            else{
                ans = mid;
                end = mid - 1;
            }
            
        }
        return ans;
    }
};