class Solution {
public:
    string reverseVowels(string s) {
        string ans = "";
        for(int i = 0; i<s.size(); i++){
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i]=='O' || s[i]=='U'
            || s[i] == 'a' || s[i] == 'e' || s[i] == 'i'|| s[i] == 'o'||s[i] == 'u'){
                ans += s[i];
                s[i] = '#';
            }
        }
        reverse(ans.begin(), ans.end());
        int l = 0;
        int r = 0;
        while(l<s.size() && r<ans.size()){
            if(s[l] == '#'){
                s[l] = ans[r]; 
                l++;
                r++;
            }else{
                l++;
            }
            
        }
        return s;
    }
};