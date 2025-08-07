class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int ans  = -1;
        // for(int i = 0; i<n; i++){
        //     if(nums[i] == target){
        //         ans = i;
        //     }
        // }
        // return ans;
        int st = 0;
        int end = n-1;
        while(st<=end){
            int mid = st+(end-st)/2;
            if(nums[mid] == target){
                ans = mid;
            }
            //ydi nums[low] <= k and k<= nums[mid] tb hum hight ko mid -1;
            if(nums[st]<=nums[mid]){
                if(nums[st]<=target && target<=nums[mid]){
                    end = mid - 1;
                }else{
                    st = mid+1;
                }
            }
            else{
                if(nums[mid] <= target && target <= nums[end]){
                    st = mid +1;
                }else{
                    end = mid - 1;
                }
            }
        }
        return ans;
    }
};