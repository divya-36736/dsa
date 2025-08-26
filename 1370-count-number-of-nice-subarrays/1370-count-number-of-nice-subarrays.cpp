class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int l = 0, r = 0;
        long long sum = 0;
        if(k < 0) return 0;

        while(r < n) {
            sum += (nums[r]%2);
            while(sum > k) {
                sum -= (nums[l]%2);
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
    } 
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        return atMost(nums, k) - atMost(nums, k - 1);
        // int cnt = 0;
        // for(int i = 0; i<n; i++){
        //     int odd = 0;
        //     for(int j = i; j<n; j++){
        //         if(nums[j]%2 == 1){
        //             odd++;
        //         }
        //         if(odd == k) cnt++;
        //     }
        // }
        // return cnt;
        //this question is same as 0, 1 array and goal given 
        //in this we convert odd no = 1, and even to 0 and do sum if sum == k then return number of subarray
        // int n = nums.size();
        // if(k<0) return 0;
        // int sum = 0;
        // int l = 0, r = 0, cnt = 0;
        // while(r<n){
        //     sum += (nums[r]%2);
        //     if(sum > k){
        //         sum = sum - (nums[l]%2);
        //         l++;
        //     }
        //     if (sum == k) {
        //         cnt++;
        //         int temp = l;
        //         while (temp < r && nums[temp] % 2 == 0) {
        //             cnt++;
        //             temp++;
        //         }
        //     }
        //     r++;
        // }
        // return cnt;
    }
};