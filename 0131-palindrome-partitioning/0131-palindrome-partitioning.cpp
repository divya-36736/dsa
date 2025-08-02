class Solution {
public:

    bool isPallindromic(string s, int i, int j){
        while(i<=j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    void parthelper(int i, string s, vector<vector<string>>&ans, vector<string>&ds){    
        //Base case
        if(i == s.size()){
            ans.push_back(ds);
            return;
        }
        //partition of string
        for(int j = i; j<s.size(); j++){
            if(isPallindromic(s, i, j)){ //if pallindrom then it push krdo in ds
                ds.push_back(s.substr(i, j-i+1)); //from i to i-j+1
                parthelper(j+1, s, ans, ds); //call next part
                ds.pop_back(); //backtracking
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>ds;
        parthelper(0, s, ans, ds);
        return ans;
    }
};