class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int lp = 0;
        int rp = n-1;
        int maxW=0;
        while(lp < rp){
           int w = rp - lp;
           int ht = min(height[lp], height[rp]);
           int area = w*ht;
           maxW = max(maxW, area);
           height[lp] < height[rp] ? lp++ : rp--;
        } 
        return maxW;
    }
};