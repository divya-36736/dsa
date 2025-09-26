class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int even = 0;
        for(int num: nums){
            int cnt = 0;
            //if(num == 0) even++;
            while(num>0){
                num /= 10;
                cnt++;
            }
            if(cnt%2 == 0){
                even++;
            }
        }
        return even;
    }
};