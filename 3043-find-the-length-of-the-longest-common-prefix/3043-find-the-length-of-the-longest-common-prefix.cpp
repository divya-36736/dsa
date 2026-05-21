class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string>set;
        for(int num: arr1){
            string s = to_string(num);
            string prefix = "";
            for(char c: s){
                prefix += c;
                set.insert(prefix);
            }
        }
        int maxi = 0;
        //for arr2
        for(int num: arr2){
            string s = to_string(num);
            string prefix = "";
            for(char c: s){
                prefix += c;
                if(set.count(prefix)){
                    maxi = max(maxi, (int)prefix.length());
                }
            }
        }
        return maxi;
    }
};