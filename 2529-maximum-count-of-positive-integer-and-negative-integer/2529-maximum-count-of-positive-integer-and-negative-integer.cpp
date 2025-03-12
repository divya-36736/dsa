class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0;
        int count2 = 0;
        
        for(int i = 0; i<n; i++){
            if(nums[i]<0){
                count1++;
            }
            else if(nums[i]>0){
                count2++;
            }
        }
        if(count1 > count2){
            return count1;
        }
        return count2;
    }
};