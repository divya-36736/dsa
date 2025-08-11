class Solution {
public:
    int trap(vector<int>& height) {
        // optimal aaproach
        int n = height.size();
        // vector<int>lmax(n,0);
        // vector<int>rmax(n,0);

        // lmax[0] = height[0];
        // rmax[n-1] = height[n-1];
        // //for left
        // for(int i = 1; i<n; i++){
        //     lmax[i] = max(lmax[i-1], height[i]);
        // }
        // //for right
        // for(int i = n-2; i>=0; i--){
        //     rmax[i] = max(rmax[i+1], height[i]);
        // }

        // int ans = 0;
        // int mini = 0;
        // for(int i = 0; i<n; i++){
        //     mini = min(lmax[i], rmax[i]);
        //     ans += mini - height[i];
        // }
        // return ans;

        // 2 pointer approach
        int l = 0;
        int r = n - 1;
        int lmax = 0;
        int rmax = 0;
        int ans = 0;
        while (l < r) {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            // check
            if (lmax < rmax) {
                ans += lmax - height[l];
                l++;
            } else {
                ans += rmax - height[r];
                r--;
            }
        }

        return ans;
    }
};