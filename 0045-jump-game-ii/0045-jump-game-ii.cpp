class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int jump= 0;
        while(l<n-1 && r<n-1){
            int farpoint = 0;
            for(int i = l; i<=r; i++){
                farpoint = max(farpoint, i+nums[i]);
            }
            l = r+1;
            r = farpoint;
            jump++;
        }
        return jump;
    }
};