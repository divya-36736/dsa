class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i = 0; i<n; i++){
            
            if(nums[i]>0){
                //move forward
                int idx = (((i+nums[i])%n + n) % n);
                ans.push_back(nums[idx]);
            }else if(nums[i] < 0){
                int idx = ((i- abs(nums[i]) + n)%n + n)%n;
                ans.push_back(nums[idx]);
            }
            else{
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};