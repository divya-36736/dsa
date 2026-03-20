class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char>st;
        
        for(int i = 0; i<n; i++){
            while(k>0 && !st.empty() && st.top() > num[i]){
                k--;
                st.pop();
            }
            st.push(num[i]);
        }
        //edge cases
        //stil k
        while(!st.empty() && k>0) {
            st.pop();
            k--;
        }

        if(st.empty()) return "0";

        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        //trim front zeros
        while(res.size() != 0 && res.back() == '0'){
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res.empty() ? "0" : res;
    }
};