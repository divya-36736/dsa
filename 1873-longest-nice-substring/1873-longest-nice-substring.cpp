class Solution {
public:
    bool isNice(string &str){
        unordered_set<char>st(str.begin(), str.end());
        for(char c: str){
            if(isalpha(c)){ //check alphanetic letter
                if(st.count(tolower(c)) == 0 || st.count(toupper(c)) == 0){
                    return false;
                }
            }
        }
        return true;
    }
    string longestNiceSubstring(string s) {
        int n = s.size();
        string res = "";

        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                string sub = s.substr(i, j-i+1);
                if(isNice(sub) && sub.size()>res.size()){
                    res = sub;
                }
            }
        }
        return res;
    }
};