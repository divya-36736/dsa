class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        vector<int>nge(n);
        if(n == 1) nge[0] = -1;
        for(int i = 0; i <= n-1; i++){
            for(int j = i+1; j <= i+n-1; j++){
                int idx = j % n;
                if(nums[idx] > nums[i]){
                    nge[i] = nums[idx];
                    break;
                }
                else{
                    nge[i] = -1;
                }

            }
        }
        return nge;
        
    }
};