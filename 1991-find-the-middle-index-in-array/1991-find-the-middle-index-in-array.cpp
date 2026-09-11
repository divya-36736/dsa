class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        int totsum = 0;
        for(int num: nums){
            totsum += num;
        }
        int leftsum = 0;
        for(int i = 0; i<n; i++){
            int rightsum = totsum-leftsum-nums[i];
            if(rightsum == leftsum) return i;
            leftsum += nums[i];
        }
        return -1;
    }
};