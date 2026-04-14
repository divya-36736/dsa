class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n = nums.size();
        int cnt  = 0;
        for(int it:nums){
            string s = to_string(it);
            for(int i = 0; i<s.size(); i++){
                if(s[i]-'0' == digit) cnt++;
            }
        }
        return cnt;
    }
};