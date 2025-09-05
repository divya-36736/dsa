class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        // remove extra digits if k still > 0
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // build result string from stack
        string res = "";
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        // reverse (since stack gives reversed order)
        reverse(res.begin(), res.end());

        // remove leading zeros
        int idx = 0;
        while (idx < res.size() && res[idx] == '0') {
            idx++;
        }

        res = res.substr(idx);

        return res.empty() ? "0" : res;
    }
};
