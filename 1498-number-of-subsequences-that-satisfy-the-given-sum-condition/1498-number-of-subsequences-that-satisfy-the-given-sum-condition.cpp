class Solution {
public:
    int const mod = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>power(n, 1);
        for(int i =1; i<n; i++){
            power[i] = (power[i-1]*2)%mod;
        }

        int l = 0; 
        int r = n-1;
        int res = 0;

        while(l<=r){
            if(nums[l] + nums[r] <= target){
                res = (res + power[r-l])%mod;
                l++;
            }
            else{
                r--;
            }
        }
        return res;
    }
};