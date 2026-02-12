class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n  = word.size();
        stack<int>st;
        int i = 0;
        while(i<n){
            if(word[i] != ch){
                st.push(word[i]);
            }
            else{
                break;
            }
            i++;
        }
        if(i != n){
            st.push(word[i]);
        }
        if(i == n){
            return word;
        }
        string ans ="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        int j = i+1;
        while(j<n){
            ans += word[j];
            j++;
        }
        return ans;
    }
};