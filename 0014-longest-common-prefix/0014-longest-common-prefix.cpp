class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //sort the array and 
        //compare 1st and last string and accodring to this i can 
        //found out the prefix
        sort(strs.begin(), strs.end());
        string s1 = strs[0];
        string s2 = strs[strs.size()-1];
        string ans = "";
        for(int i = 0; i<s1.size(); i++){
            if(s1[i] == s2[i]){
                ans += s1[i];
            }
            else{
                break;
            }
        }
        return ans;
    }
};