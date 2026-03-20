class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        stack<char> st;
        int collisions = 0;
        for (char c : directions) {
            if (c == 'L') {
                if (!st.empty() && st.top() == 'R') {
                    collisions += 2;
                    st.pop();
                    // more R's behind will hit this S then +1
                    while (!st.empty() && st.top() == 'R') {
                        collisions += 1;
                        st.pop();
                    }
                    st.push('S');
                } else if (!st.empty() && st.top() == 'S') {
                    collisions += 1;
                    st.push('S');
                }
            } else if (c == 'R') {
                st.push('R');
            } else {
                //'S
                while(!st.empty() && st.top() == 'R'){
                    collisions += 1;
                    st.pop();
                }
                st.push('S');
            }
        }
        return collisions;
    }
};