class Solution {
public:
    void solve(int i, string &digits, vector<string>&ans, string &output, string mapping[]){
        if(i == digits.size()){
            ans.push_back(output);
            return;
        }
        int value = digits[i]-'0';
        string word = mapping[value];
        for(int j = 0; j<word.size(); j++){
            output.push_back(word[j]);
            solve(i+1, digits, ans, output, mapping);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) return ans;
        
        string output = "";
        string mapping[10] = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        solve(0, digits, ans, output, mapping);
        return ans;
    }
};