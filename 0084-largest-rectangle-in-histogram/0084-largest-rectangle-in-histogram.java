class Solution {
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        Stack<Integer>st = new Stack<>();
        int maxi = 0;

        for(int i = 0; i<=n; i++){
            while(!st.empty() && (i == n || heights[st.peek()] >= heights[i])){
                int h = heights[st.peek()];
                st.pop();

                int w = st.empty() ? i: i-st.peek()-1;
                maxi = Math.max(maxi, h*w);
            }
            st.push(i);
        }
        return maxi;
    }
}