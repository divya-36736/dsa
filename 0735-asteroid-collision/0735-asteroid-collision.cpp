class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> st;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > 0 || st.empty() || st.top() < 0) {
                // Push positive asteroids or negative asteroids if stack is empty or top is negative
                st.push(arr[i]);
            } else {
                // Current asteroid is negative, handle collisions
                while (!st.empty() && st.top() > 0 && st.top() < abs(arr[i])) {
                    // Pop smaller positive asteroids
                    st.pop();
                }
                if (!st.empty() && st.top() == abs(arr[i])) {
                    // Equal size asteroids collide and both are destroyed
                    st.pop();
                } else if (st.empty() || st.top() < 0) {
                    // No positive asteroid or only negative asteroids remain, push current
                    st.push(arr[i]);
                }
                // If st.top() > abs(arr[i]), negative asteroid is destroyed, do nothing
            }
        }
        
        // Transfer stack to result vector in correct order
        vector<int> ans(st.size());
        int i = st.size() - 1;
        while (!st.empty()) {
            ans[i--] = st.top();
            st.pop();
        }
        return ans;
    }
};