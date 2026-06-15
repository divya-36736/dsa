class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        int mod = 26;
        string s = "";
        for(auto &it: words){
            int charsum = 0;
            for(char &c: it){
                int ch = c-'a';
                charsum += weights[ch];
            }
            charsum = charsum % mod;
            s += 'z'-charsum;
        }
        return s;
    }
};