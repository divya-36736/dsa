class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int idx1 = 1;
        int idx2 = 1;
        vector<int> temp;
        //  for(int i = 1; i<nums1.size(); i++){
        //     if(nums1[i] != nums1[i-1]){
        //         nums1[idx1++] = nums1[i];
        //     }
        //     nums1.resize(idx1);
        //  }
        //  for(int j = 1; j<nums2.size(); j++){
        //     if(nums2[j] != nums2[j-1]){
        //         nums2[idx2++] = nums2[j];
        //     }
        //     nums2.resize(idx2);
        //  }
         int x = 0;
         int y = 0;
         while(x < nums1.size() && y < nums2.size()){
            if(nums1[x] == nums2[y]){
                temp.push_back(nums1[x]);
                x++;
                y++;
            }
            else if(nums1[x] < nums2[y]){
                x++;
            }
            else{
                y++;
            }
         }
         return temp;
    }
};