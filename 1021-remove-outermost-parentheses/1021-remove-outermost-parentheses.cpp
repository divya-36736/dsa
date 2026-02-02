class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string ans = "";
        int idx = 0;
        for(int i = 0; i<s.size(); i++){
            if(cnt == 0){
                idx = i+1;
            }
            if(s[i] == '(') cnt++;
            else cnt--;
            if(cnt == 0){
                ans += s.substr(idx, i-idx);
            }
        }
        return ans;
    }
};