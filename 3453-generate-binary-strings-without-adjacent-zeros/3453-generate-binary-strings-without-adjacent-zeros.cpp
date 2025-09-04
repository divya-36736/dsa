class Solution {
public:
    void backTrack(int n, string &curr, vector<string>&ans){
        //base case
        if(curr.size()==n){
            ans.push_back(curr);
            return;
        }
        //if i take 1
        curr.push_back('1');
        backTrack(n, curr, ans);
        curr.pop_back();
        //if i take 0;
        if(curr.empty() || curr.back() != '0'){
            curr.push_back('0');
            backTrack(n, curr, ans);
            curr.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        vector<string>ans;
        string curr = "";
        backTrack(n,curr,ans);
        return ans;
    }
};