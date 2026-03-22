class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>nse(n);
        vector<int>pse(n);
        stack<int>st;
        //pse 
        for(int i =0; i<n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                st.pop();
            }
            pse[i] = st.empty()? -1 : st.top();

            st.push(i);
        }
        while(!st.empty()) st.pop();
        //nse
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            nse[i] = st.empty()? n: st.top();
            st.push(i);
        }

        int maxArea = 0;
        for(int i = 0; i<n; i++){
            maxArea = max(maxArea, heights[i]*(nse[i]-pse[i]-1));
        }
        return maxArea;
    }
};