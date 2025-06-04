class Solution {
public:

    int sumByD(vector<int>& nums, int div){
        int n = nums.size();
        
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += ceil((double)nums[i]/(double)div);
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        if(n>threshold) return -1;
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while(low <= high){
            int mid = low + (high-low)/2;
            if (sumByD(nums, mid) <= threshold) {
                high = mid-1;
            } else {
                low = mid + 1; 
            }
        }
        return low;

        //Brute approach
        // int maxi = *max_element(nums.begin(), nums.end());
        // for(int d = 1; d<=maxi; d++){
        //     int sum = 0;
        //     for(int i = 0; i<n; i++){
        //         sum += ceil((double)nums[i]/(double)d);
        //     }
        //     if(sum <= threshold){
        //         return d;
        //         break;
        //     }
        // }
        // return maxi;

        //optimal approach
        // int maxi = *max_element(nums.begin(), nums.end());
        // int st = 1;
        // int end = maxi;
        // while(st<end){
        //     int mid = st + (end-st)/2;
        //     int sum = 0;
        //     for(int i = 0; i<n; i++){
        //         sum += ceil((double)nums[i]/(double)mid);
        //     }
        //     if(sum <= threshold){
        //         end = mid;
        //     }
        //     else{
        //         st = mid+1;
        //     }
        // }
        // return st;

        
        
    }
};