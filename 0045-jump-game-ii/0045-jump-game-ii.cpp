class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int l = 0, r = 0;
        // take l , and r at 0 and now a loop chalenge joh l to r tk chalega phir usme hum ek farpoint lenge joh maxize krega r ko 
        while (r < n - 1) {
            int farpoint = 0;
            for (int i = l; i <= r; i++) {
                farpoint = max(farpoint, i + nums[i]);
            }
            l = r + 1;
            r = farpoint;
            jumps++;
        }
        return jumps;
    }
};
