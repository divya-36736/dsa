class Solution {
public:
    
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int f = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
            f += i*nums[i];
        }
        int maxi = f;
        for(int i = 1; i<n; i++){
            f += sum -n*nums[n-i];
            maxi = max(maxi, f);
        }
        return maxi;
    }
};