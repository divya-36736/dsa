class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char>st(brokenLetters.begin(),brokenLetters.end());
        int cnt = 0;
        stringstream ss(text);
        string word;
        while(ss >> word){
            bool canType = true;
            for(char &c:word){
                if(st.find(c) != st.end()){
                    canType = false;
                    break;
                }
            }
            if(canType)cnt++;
        }
        return cnt;
    }
};