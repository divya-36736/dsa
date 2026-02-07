class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int sign = 1;
        int i = 0;
        
        while(i<n && s[i] == ' '){
            i++;
        }
        //check sign
        if(i<n && (s[i] == '-' || s[i] == '+')){
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        long ans = 0;
        while(i<n && isdigit(s[i])){
            ans = ans * 10 + (s[i] - '0');
            if(sign == 1 && ans > INT_MAX) return INT_MAX;
            if(sign == -1 && -ans < INT_MIN) return INT_MIN;
            i++;
        }
        return (int)(sign*ans);
    }
};