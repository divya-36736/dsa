class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        //brute force

        // for(int i = 0; i<n; i++){
        //     for(int j = i+1; j<n; j++){
        //         if(nums[i]==nums[j] && abs(i-j)<=k){
        //             return true;
        //         }
        //     }
        // }
        // return false;

        //optimal approach
       unordered_set<int>st;
       for(int i = 0; i<n; i++){
        if(st.count(nums[i])){
            return true; //duplicste found within k distance
        }
        st.insert(nums[i]);
        if(st.size()>k){
            st.erase(nums[i-k]);
        }
       }
       return false;
    }
};