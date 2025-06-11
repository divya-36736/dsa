class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n != m) return false;
        // for(int i = 0; i<n; i++){
        //     char c1 =  s[i];
        //     char c2 = t[i];
        //     for(int j = 0; j<n; j++){
        //         if(s[j] == c1 && t[j] != c2){
        //             return false;
        //         }
        //         else if(t[j] == c2 && s[j] != c1){
        //             return false;
        //         }
        //     }
        // }
        // return true;
        unordered_map<char, int> m1, m2;
        for(int i = 0; i<n; ++i){
            if(m1.find(s[i]) == m1.end()){
                m1[s[i]] = i;
            }
            if(m2.find(t[i]) == m2.end()){
                m2[t[i]] = i;
            }
            if(m1[s[i]] != m2[t[i]]){
                return false;
            }
        }
        return true;
    }
};