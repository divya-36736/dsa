class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return true;
        for(int i = 1; i<n; i++){
            if(nums[i]<nums[i-1]){
                break;
            }
            if(i == n-1) return true;
        }

        for(int i = 1; i<n; i++){
            if(nums[i] > nums[i-1]){
                break;
            }
            if(i == n-1) return true;
        }
        return false;
    }
};