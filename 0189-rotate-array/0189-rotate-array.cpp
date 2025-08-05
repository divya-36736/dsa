class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // int n = nums.size();
        // k = k%n;
        // vector<int>temp(n);
        // //optimal approch
        // // reverse(nums.begin(), nums.end());
        // // reverse(nums.begin(), nums.begin()+k);
        // // reverse(nums.begin()+k, nums.end());

        // //BRUTE approach
        // int j = 0;
        // for(int i = n-k; i<n; i++){
        //     temp[j] = nums[i];
        //     j++;
        // }
        // for(int i = 0; i<n-k; i++){
        //     temp[j] = nums[i];
        //     j++;
        // }
        // for(int i = 0; i<n; i++){
        //     nums[i] = temp[i];
        // }
       
        int n = nums.size();
        vector<int>temp(n);
        for(int i = 0; i<n; i++){
            temp[(i+k)%n] = nums[i];
        }
        //copy temp to num
        nums = temp;
    }
};