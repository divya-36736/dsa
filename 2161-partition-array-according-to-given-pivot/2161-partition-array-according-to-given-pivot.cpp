class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n= nums.size();
        
        vector<int>before, after;
        int pivotcnt = 0;
        for(int i = 0; i<n; i++){
            if(nums[i]<pivot){
                before.push_back(nums[i]);
            }
            else if(nums[i]>pivot){
                after.push_back(nums[i]);
            }
            else{
                pivotcnt++;
            }
        }
        while(pivotcnt>0){
            before.push_back(pivot);
            pivotcnt--;
        }

        for(int i = 0; i<after.size(); i++){
            before.push_back(after[i]);
        }
        return before;
    }
};