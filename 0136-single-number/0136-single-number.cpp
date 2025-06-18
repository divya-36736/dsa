class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        // int a = nums[n - 1];
        // int i = 0;
        // int j = i + 1;
        // if (n == 1) return nums[i];
        // while (i < n - 1 && j < n) {
        //     if (nums[i] != nums[j]) {
        //         a = nums[i]; 
        //         break;
        //     }
        //     i += 2;
        //     j = i + 1;
        // }
        // return a;

        //xor
        //(x^x = 0)
        //(x^0=x)
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            ans ^= nums[i];
        }
        return ans;
    }
};