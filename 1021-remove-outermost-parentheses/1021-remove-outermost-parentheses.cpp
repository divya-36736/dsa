class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        int cnt = 0;
        string str = "";
        for(int i = 0; i<n; i++){
            if(s[i] == '('){
                if(cnt>0) str += s[i];
                cnt++;
            }else{
                if(cnt > 0) cnt--;
                if(cnt >0){
                    str += s[i];
                }
            }
        }
        return str;
    }
};