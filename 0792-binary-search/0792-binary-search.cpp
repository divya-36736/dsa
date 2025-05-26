class Solution {
public:
    
    int bs(vector<int>& nums, int st, int end, int target){
        
        if(st>end) return -1;
        int mid = st + (end-st)/2;

        if(nums[mid] == target) return mid;
        else if(target > nums[mid]) return bs(nums, mid+1, end, target);
        return bs(nums, st, mid-1, target);
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        return  bs(nums, 0, n-1, target);
        // while(st <= end) {
        //     int mid = st + (end - st) / 2;
        //     if(nums[mid] == target) return mid; 
        //     else if(nums[mid] < target) st = mid + 1; 
        //     else end = mid - 1; 
        // }
        //int mid = st + (end-st)/2;
        // for(int i = 0; i<n; i++){
        //     if(nums[i] == target){
        //        return i;
        //     }
            
        // }
        // return -1;
    }
};