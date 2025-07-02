class Solution {
public:

    int atMost(vector<int>& nums, int goal) {
        int n = nums.size();
        int count = 0;
        int l = 0, r = 0;
        long long sum = 0;
        if(goal < 0) return 0;

        while(r < n) {
            sum += nums[r];
            while(sum > goal) {
                sum -= nums[l];
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
    } 


    int numSubarraysWithSum(vector<int>& nums, int goal) {
         return atMost(nums, goal) - atMost(nums, goal - 1);



        // int n = nums.size();
        // int count = 0;
        // for(int i = 0; i<=n-1; i++){
        //     int sum = 0;
        //     for(int j= i; j<=n-1; j++){
        //         sum += nums[j];
        //         if(sum == goal){
        //             count++;
        //         }
        //     }
        // }
        // return count;

        
    }
};