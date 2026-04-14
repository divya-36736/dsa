class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n = nums.size();
        int cnt  = 0;
        for(int it:nums){
            while(it){
                int a = it%10;
                it /= 10;
                if(a == digit) cnt++;
            }
        }
        return cnt;
    }
};