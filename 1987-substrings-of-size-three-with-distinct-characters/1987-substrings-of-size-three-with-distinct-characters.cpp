class Solution {
public:
    bool isGood(string &str){
        unordered_set<char>st(str.begin(), str.end());
        return st.size() == str.size();  // all chars must be unique
    }

    int countGoodSubstrings(string s) {
        //int n = s.size();
        // int cnt = 0;
        // for(int i = 0; i<=n-3; i++){
        //     string sub = s.substr(i, 3);
        //     if(isGood(sub)){
        //         cnt++;
        //     }
        // }
        // return cnt;

        int n = s.size();
        if (n < 3) return 0;

        int cnt = 0;
        for (int i = 0; i <= n - 3; i++) {
            char a = s[i], b = s[i+1], c = s[i+2];
            if (a != b && b != c && a != c) {
                cnt++;
            }
        }
        return cnt;
    }
};