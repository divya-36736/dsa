class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n != m) return false;
        for(int i = 0; i<n; i++){
            char c1 =  s[i];
            char c2 = t[i];
            for(int j = 0; j<n; j++){
                if(s[j] == c1 && t[j] != c2){
                    return false;
                }
                else if(t[j] == c2 && s[j] != c1){
                    return false;
                }
            }
        }
        return true;
    }
};