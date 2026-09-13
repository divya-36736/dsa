class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        long long zeros = 0;
        long long ans  = 0;
        for(int i = n-1; i>=0; i--){
            if(s[i] == '0') zeros++;
            else ans += zeros;
        }
        return ans;
    }
};