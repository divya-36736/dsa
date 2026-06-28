class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = n-1;
        long long sum = 0 ;
        while(i>=0 && k>0){
            if(mul <= 0) mul = 1;
            sum += 1LL*nums[i] * mul;
            mul--;
            k--;
            i--;
        }
        return sum;
    }
};