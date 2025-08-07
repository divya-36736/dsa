class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mpp;
        int maxi = 1;
        for(int i = 0; i<n; i++){
            mpp[nums[i]]++;
        }
        for(auto it : mpp){
           if(it.second == 1){
            return it.first;
           }
        }
        return -1;
    }
};