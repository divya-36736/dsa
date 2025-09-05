class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        // //bruteforce approach
        // long long sum = 0;
        // for(int i = 0; i<n; i++){
        //     int mini = INT_MAX;
        //     int maxi = INT_MIN;
        //     for(int j = i; j<n; j++){
        //         mini = min(mini, nums[j]);
        //         maxi = max(maxi, nums[j]);
        //         sum += abs(maxi - mini);
        //     }
        // }
        // return sum;

        //optimal
        vector<int> pse(n), nse(n), pge(n), nge(n);
        stack<int> st;

        // Previous Smaller (strictly smaller)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
            pse[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Smaller (strictly smaller OR equal to handle duplicates)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            nse[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Previous Greater (strictly greater)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            pge[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Greater (strictly greater OR equal to handle duplicates)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            nge[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }

        long long res = 0;

        for (int i = 0; i < n; i++) {
            long long maxContribution = 1LL * nums[i] * pge[i] * nge[i];
            long long minContribution = 1LL * nums[i] * pse[i] * nse[i];
            res += (maxContribution - minContribution);
        }

        return res;
    }
};