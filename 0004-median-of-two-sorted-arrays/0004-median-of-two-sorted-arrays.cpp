class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int>ans;
        int i = 0;
        int j = 0;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }else{
                ans.push_back(nums2[j]);
                j++;
            }
        }

        // add remaining elements
        while(i < n1) ans.push_back(nums1[i++]);
        while(j < n2) ans.push_back(nums2[j++]);

        int n = ans.size();

        if(n % 2 == 1){
            return ans[n/2];
        } else {
            return (ans[n/2 - 1] + ans[n/2]) / 2.0;
        }
    }
};