class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        string ans = "";

        for(int i = s.size()-1; i>=0; i--){
            if(s[i] == ' '){
                if(!ans.empty()){
                    reverse(ans.begin(), ans.end());
                    if(!res.empty()){
                        res += " ";
                    }
                    res += ans;
                    ans = "";
                }
            }else{
                ans += s[i];
            }
        }
        if(!ans.empty()){
            reverse(ans.begin(), ans.end());
            if(!res.empty()) res += " ";
            res += ans;
        }
        return res;
    }
};