class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        // brute force approach
        //  int maxi = 0;
        //  for(int i=0; i<n; i++){
        //      int mini = INT_MAX;
        //      for(int j = i; j<n; j++){
        //          mini = min(mini, heights[j]);
        //          maxi = max(maxi, mini*(j-i+1));
        //      }
        //  }
        //  return maxi;

        // optimal
        
        vector<int> right(n), left(n);
        int ans = 0;
        stack<int> s;

        // Right boundaries
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i); // push index, not height
        }

        while (!s.empty())
            s.pop(); // clear stack

        // Left boundaries
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop(); // must pop, not s.top()
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i); // push index, not height
        }

        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int currarea = heights[i] * width;
            ans = max(ans, currarea);
        }
        return ans;
    }
};