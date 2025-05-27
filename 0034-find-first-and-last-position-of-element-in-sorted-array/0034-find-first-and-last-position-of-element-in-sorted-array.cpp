class Solution {
public:
    //using upper and lower bound

    // int lowerBound(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     int st = 0;
    //     int end = n-1;
    //     int ans = n;
    //     while(st <= end){
    //         int mid = st + (end - st)/2;
    //         if(nums[mid] >= target){
    //             ans = mid;
    //             end = mid - 1;
    //         }
    //         else{
    //             st = mid+1;
    //         }
    //     }
    //     return ans;
    // }

    // int upperBound(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     int st = 0;
    //     int end = n-1;
    //     int ans = n;
    //     while(st <= end){
    //         int mid = st + (end - st)/2;
    //         if(nums[mid] > target){
    //             ans = mid;
    //             end = mid - 1;
    //         }
    //         else{
    //             st = mid + 1;
    //         }
    //     }
    //     return ans;
    // }
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int n = nums.size();
//         int lb = lowerBound(nums, target);
//         int up = upperBound( nums, target);
//         if(lb == n || nums[lb] != target ) return {-1, -1};
//         return {lb, up-1};
//     }
// };


    //using without lower and upper bound

    int first(vector<int>& nums, int target){
        int n = nums.size();
        int st = 0;
        int end = n-1;
        int first = -1;
        while(st <= end){
            int mid = st + (end - st)/2;
            if(nums[mid] == target){
                first = mid;
                end = mid - 1;
            }
            else if(nums[mid] < target){
                st = mid + 1;
            }
            else end = mid - 1;
        }
        return first;
    }

    int last(vector<int>& nums, int target){
        int n = nums.size();
        int st = 0;
        int end = n-1;
        int last = -1;
        while(st <= end){
            int mid = st + (end - st)/2;
            if(nums[mid] == target){
                last = mid;
                st = mid + 1;
            }
            else if(nums[mid] < target){
                st = mid + 1;
            }
            else end = mid - 1;
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target){
        int n = nums.size();
        int fst = first(nums, target);
        int lst = last(nums, target);
        if(fst == -1) return {-1,-1};
        return {fst, lst};
    }
};