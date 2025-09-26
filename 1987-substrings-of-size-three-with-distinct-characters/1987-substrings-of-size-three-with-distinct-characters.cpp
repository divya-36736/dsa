class Solution {
public:
    bool isGood(string &str){
        unordered_set<char>st(str.begin(), str.end());
        return st.size() == str.size();  // all chars must be unique
    }
    
    int countGoodSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i = 0; i<=n-3; i++){
            string sub = s.substr(i, 3);
            if(isGood(sub)){
                cnt++;
            }
        }
        return cnt;
    }
};