class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return -1;
        if(n == 2){
            if(nums[0] == 1) return 1;
        }
        vector<long long>leftsum(n);
        vector<long long>rightPro(n);
        leftsum[0] = nums[0];
        for(int i = 1; i<n; i++){
            leftsum[i] = leftsum[i-1]+nums[i];
        }
        rightPro[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--){
            if(rightPro[i+1] > LLONG_MAX / nums[i]){
                rightPro[i] = LLONG_MAX;
            } else {
                rightPro[i] = rightPro[i+1] * nums[i];
            }
        }

        for(int i = 1; i<n-1; i++){
            if(leftsum[i-1] == rightPro[i+1]){
                return i;
            }
        }
        return -1;
    }
};