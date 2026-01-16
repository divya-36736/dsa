class Solution {
public:
    bool static compare(string &s, string &t){
        return s.size() < t.size();
    }

    bool checkPossible(string &s, string &t){
        if(s.size() != t.size()+1) return false;
        int i = 0; //for s
        int j = 0; //for t
        while(i<s.size()){
            if(j<t.size() && s[i] == t[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        if(i == s.size() && j == t.size()) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), compare); //size ke according sorting
        vector<int>dp(n, 1);
        int maxlen = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                if(checkPossible(words[i], words[j]) && dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1; //length update
                }
            }
            if(dp[i]>maxlen) maxlen = dp[i];
        }
        return maxlen;
    }
};