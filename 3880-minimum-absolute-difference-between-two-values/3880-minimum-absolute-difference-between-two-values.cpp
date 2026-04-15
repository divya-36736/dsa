class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i =0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if((nums[i] == 1 && nums[j] == 2) || nums[i] == 2 && nums[j] == 1){
                    ans = min(ans, abs(i-j));
                }
            }
        }
        return ans == INT_MAX?-1:ans;
    }
};