class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int l = 0;
        int r = 0;
        while(r<n-1){
            int farpoint  = 0;
            for(int i = l; i<=r; i++){
                farpoint = max(farpoint, i+nums[i]);
            }
            l= r + 1;
            r = farpoint;
            jumps++;
        }
        return jumps;
    }
};