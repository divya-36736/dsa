class Solution {
public:
    bool isCaps(char a, char b){
        return abs(a-b) == 32;
    }
    string makeGood(string s) {
        string ans = "";
        // for(char c: s){
        //     if(!ans.empty() && isCaps(ans.back(), c)) ans.pop_back();
        //     else ans += c;
        // }
        // return ans;

        stack<char>st;
        for(char c: s){
            if(!st.empty() && isCaps(st.top(), c)) st.pop();
            else  st.push(c);
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};