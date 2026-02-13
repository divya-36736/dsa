class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre;
        pre.push_back(nums[0]);
        for(int i = 1; i<n; i++){
            pre.push_back(pre[i-1] + nums[i]);
        }
        int ans = -1;
        for(int i = 0; i<pre.size(); i++){
             int left = (i == 0) ? 0 : pre[i-1];
            int right = pre[pre.size()-1] - pre[i];
            if(left == right){
                return i;
            }
        }
        return -1;
    }
};