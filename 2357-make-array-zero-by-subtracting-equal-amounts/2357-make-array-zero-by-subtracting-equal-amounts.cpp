class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int high = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        int cnt  = 0;
        while(high){
            int mini = INT_MAX;
            for(int i = 0; i<n; i++){
                if(mini > nums[i] && nums[i] != 0){
                    mini = nums[i];
                }
            }
            if(mini == INT_MAX){
                return 0;
                break;
            }
            for(int i = 0; i<n; i++){
                if(nums[i] != 0){
                    nums[i] -= mini;
                }
            }
            cnt++;
            high -= mini;
        }
        return cnt;
    }
};