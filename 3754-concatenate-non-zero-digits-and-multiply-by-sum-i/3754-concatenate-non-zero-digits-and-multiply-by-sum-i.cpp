class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        if(n == 0) return 0;
        string ans = "";
        string s = to_string(n);
        for(int i = 0; i<s.size(); i++){
            if(s[i] != '0'){
                ans += s[i];
                sum += s[i]-'0';
            }
        }
        long long ans1 = stol(ans);
        return ans1*sum;
    }
};