class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int cnt = 0;
        
        // Iterate through all possible pairs of points
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue; // Skip same point
                
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                
                // Check if (x1, y1) is above and to the left of (x2, y2)
                if (x1 <= x2 && y1 >= y2) {
                    bool valid = true;
                    // Check if any other point lies within the rectangle
                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j) continue;
                        int x3 = points[k][0], y3 = points[k][1];
                        // If point (x3, y3) lies within the rectangle
                        if (x3 >= x1 && x3 <= x2 && y3 <= y1 && y3 >= y2) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) cnt++;
                }
            }
        }
        
        return cnt;
    }
};