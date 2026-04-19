class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int maxi = 0;
        int l = 0;
        int r = 0;
        while(r<n2 && l<n1){
             if (nums1[l] <= nums2[r]) {
                maxi = max(maxi, r - l);
                r++;   
            } else {
                l++; 
            }
        }
        return maxi;
    }
};