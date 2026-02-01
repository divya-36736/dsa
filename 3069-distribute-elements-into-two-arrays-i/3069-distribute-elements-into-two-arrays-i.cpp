class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr1(1, 0);
        vector<int>arr2(1, 0);
        arr1[0] = nums[0];
        arr2[0] = nums[1];
        for(int i = 2; i<n; i++){
            if(arr1[arr1.size()-1] > arr2[arr2.size()-1]){
                arr1.push_back(nums[i]);
            }else{
                arr2.push_back(nums[i]);
            }
        }
        for(int i = 0; i<arr2.size(); i++){
            arr1.push_back(arr2[i]);
        }
        return arr1;
    }
};