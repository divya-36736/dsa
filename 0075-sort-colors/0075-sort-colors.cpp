class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        // //sort(nums.begin(), nums.end());
        
        // for(int i = 0; i<n; i++){
        //     for(int j= i+1; j<n; j++){
        //         if(nums[i] > nums[j]){
        //             swap(nums[i], nums[j]);
        //         }
        //     }
        // }
    //count0, count1, count2 alg alg variabal banao phir put kro
    int count0 = 0, count1= 0, count2 = 0;
    for(int i = 0; i<n; i++){
        if(nums[i] == 0){
            count0++;
        }else if(nums[i] == 1){
            count1++;
        }
        else count2++;
    }

    for(int i = 0; i<count0; i++) nums[i] = 0;
    for(int i = count0; i<count0+count1; i++) nums[i] = 1;
    for(int i = count0+count1; i<n; i++) nums[i] = 2;
    }
};