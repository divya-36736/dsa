class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        //time issue
        // for(int i = 0; i<n; i++){
        //     for(int j = i+1; j<n; j++){
        //         if(nums[i] == nums[j]){
        //            return nums[i];
        //         }
        //     }
        // }
        // return -1;
        vector<int>freq(n+1, 0);
        for(int i = 0; i<n; i++){
            freq[nums[i]]++;
            if(freq[nums[i]]>1){
                return nums[i];
            }
        }
        return -1;
        
    }
};