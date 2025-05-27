class Solution {
public:
    //using upper and lower bound

    int lowerBound(vector<int>& nums, int target) {
        // code here
        int n = nums.size();
        int st = 0;
        int end = n-1;
        int ans = n;
        while(st <= end){
            int mid = st + (end - st)/2;
            if(nums[mid] >= target){
                ans = mid;
                end = mid - 1;
            }
            else{
                st = mid+1;
            }
        }
        return ans;
    }

    int upperBound(vector<int>& nums, int target) {
        // code here
        int n = nums.size();
        int st = 0;
        int end = n-1;
        int ans = n;
        while(st <= end){
            int mid = st + (end - st)/2;
            if(nums[mid] > target){
                ans = mid;
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerBound(nums, target);
        int up = upperBound( nums, target);
        if(lb == n || nums[lb] != target ) return {-1, -1};
        return {lb, up-1};
    }
};