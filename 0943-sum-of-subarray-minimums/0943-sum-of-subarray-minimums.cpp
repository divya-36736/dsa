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

        int n = arr.size();

        vector<int> left(n), right(n);
        stack<int> st;

        // Step 1: Find previous less element distance (left span)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }

        // Clear stack for next pass
        while (!st.empty()) st.pop();

        // Step 2: Find next less-or-equal element distance (right span)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }

        // Step 3: Calculate contributions
        long long res = 0;
        for (int i = 0; i < n; i++) {
            long long contrib = (1LL * arr[i] * left[i] * right[i]) % MOD;
            res = (res + contrib) % MOD;
        }

        return (int)res;
    }
};
