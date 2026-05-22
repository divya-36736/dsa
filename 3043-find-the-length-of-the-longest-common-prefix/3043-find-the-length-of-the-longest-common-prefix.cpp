class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string>st;
        for(auto num: arr1){
            string s = to_string(num);
            string prefix = "";
            for(char &c:s){
                prefix += c;
                st.insert(prefix);
            }
        }
        int maxi = 0;
        for(auto num: arr2){
            string s = to_string(num);
            string prefix = "";
            for(char &c: s){
                prefix += c;
                if(st.count(prefix)){
                    maxi = max(maxi, (int)prefix.length());
                }
            }
        }
        return maxi;
    }
};