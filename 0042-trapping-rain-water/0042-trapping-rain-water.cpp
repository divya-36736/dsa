class Solution {
public:
    int trap(vector<int>& height) {
        //2 pointer approach
        int n = height.size();
        int left = 0;
        int right = n-1;
        int maxleft = 0;
        int maxright = 0;
        int totalwater = 0;
        while(left < right){
            maxleft = max(maxleft, height[left]);
            maxright = max(maxright, height[right]);

            if(maxleft < maxright){
                totalwater += maxleft - height[left];
                left++;
            }
            else{
                totalwater += maxright - height[right];
                right--;
            }
        }
        return totalwater;
    }
};