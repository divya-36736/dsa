class Solution {
public:
    int help(int i, string &s, int sign, long long num){
        if(i >= s.size() || !isdigit(s[i])) return (sign*num);

        num = num * 10 + s[i] - '0';
        if(sign*num <= INT_MIN) return INT_MIN;
        if(sign*num >= INT_MAX) return INT_MAX;

        return help(i+1, s, sign, num);
    }
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        while(i<n && s[i] == ' '){
            i++;
        }

        int sign = 1;
        if(i<n && (s[i] == '-' || s[i] == '+')){
            sign = (s[i] == '-')? -1 : 1;
            i++;
        }
        return help(i, s, sign, 0);
    }
};