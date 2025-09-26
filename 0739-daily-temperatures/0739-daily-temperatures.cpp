class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        //TLE
        // vector<int> ans(n, 0);
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         if (nums[j] > nums[i]) {
        //             ans[i] = j - i;
        //             break; 
        //         }
        //     }
        // }
        // return ans;

        vector<int>ans(n, 0);
        stack<int>st;
        for(int i = 0; i<n; i++){
            while(!st.empty() && nums[i]>nums[st.top()]){
                int idx = st.top();
                st.pop();
                ans[idx] = i-idx;
            }
            st.push(i);
        }
        return ans;
    }
};
