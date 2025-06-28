class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        //brute force approach

        // int maxlen = 0;
        // int n = nums.size();
        // for(int i = 0; i<n; i++){
        //     int zero = 0;
        //     for(int j = i; j<n; j++){
        //         if(nums[j] == 0){
        //             zero++;
        //         }
        //         if(zero <= k){
        //             int len = j-i+1;
        //             maxlen = max(maxlen, len);
        //         }else{
        //             break;
        //         }
        //     }
        // }
        // return maxlen;

        // int maxlen = 0; 
        // int l = 0; 
        // int r = 0;
        // int n = nums.size();
        // int zero = 0;
        // while(r < n){
        //     if(nums[r] == 0) zero++;
        //     while(zero > k){
        //         if(nums[l] == 0) zero--;
        //         l++;
        //     }
        //     if(zero <= k){
        //         int len = r-l+1;
        //         maxlen = max(len, maxlen);
        //     }
        //     r++;
        // }
        // return maxlen;

        
        int n = nums.size();
        int l = 0;
        int r = 0;
        int zero = 0;
        int maxlen = 0;
        
        while (r < n) {
            if (nums[r] == 0) {
                zero++;
            }
            while (zero > k) { 
                if (nums[l] == 0) {
                    zero--;
                }
                l++;
            }
           
            maxlen = max(maxlen, r - l + 1);
            r++; 
        }
        
        return maxlen;
    }
};