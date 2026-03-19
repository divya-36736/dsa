class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        //mininum
        vector<int>leftmin(n), rightmin(n);
        //pse
        for(int i = 0; i<n; i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            leftmin[i] = st.empty()?i+1:i-st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        //nse
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            rightmin[i] = st.empty() ? n-i : st.top()-i;
            st.push(i);
        }

        while(!st.empty()) st.pop();
        vector<int>leftmax(n), rightmax(n);
        //pge
        for(int i = 0; i<n; i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            leftmax[i] = st.empty()? i+1 : i-st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        //nge
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            rightmax[i] = st.empty() ? n-i : st.top() - i;
            st.push(i);
        }
        //contribution 
        long long maxsum = 0;
        long long minsum = 0;
        for(int i = 0; i<n; i++){
            minsum += (long long)nums[i] * leftmin[i] * rightmin[i];
            maxsum += (long long)nums[i] * leftmax[i] * rightmax[i];
        }
        return maxsum - minsum;
    }
};