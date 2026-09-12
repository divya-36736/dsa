class Solution {
public:
    bool isPalindrom(string &s, int i, int j){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void f(int i, string s, vector<vector<string>>&ans, vector<string>&ds){
        int n = s.size();
        if(i == s.size()){
            ans.push_back(ds);
            return;
        }

        for(int j = i; j<n; j++){
            if(isPalindrom(s, i, j)){
                ds.push_back(s.substr(i, j-i+1));
                f(j+1, s, ans, ds);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>>ans;
        vector<string>ds;
        f(0, s, ans, ds);
        return ans;
    }
};