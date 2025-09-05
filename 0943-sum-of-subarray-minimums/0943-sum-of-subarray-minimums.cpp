class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        // int n = arr.size();
        // long long sum = 0;

        // for (int i = 0; i < n; i++) {
        //     int mini = INT_MAX;
        //     for (int j = i; j < n; j++) {
        //         mini = min(mini, arr[j]);
        //         sum = (sum + mini) % MOD;
        //     }
        // }
        // return sum;

//optimal solution using NSE, PSE(next smallest element and previous smallest element) 
//form pse and nse we find the contribution of every element
        
        int n = arr.size();
        vector<int> pse(n), nse(n);
        stack<int> st;

        // Previous Smaller Element (distance)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }

        // clear stack
        while (!st.empty()) st.pop();

        // Next Smaller Element (distance)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }

        // Contribution
        long long res = 0;
        for (int i = 0; i < n; i++) {
            long long contrib = (1LL * arr[i] * pse[i] * nse[i]) % MOD;
            res = (res + contrib) % MOD;
        }

        return (int)res;
    }
};
