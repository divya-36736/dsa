class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        //1st take unorderd_map and then push the all characters
        //of every qwertyuiop, asdfghjkl,asdfghjkl.
        //1st all character convert it into lowercase and 
        //then check all characeter of word belongs to same 
        //row then return true, otherwise false;
        vector<string>ans;
        unordered_map<char, int>mp;

        string s1 = "qwertyuiop";
        string s2 = "asdfghjkl";
        string s3 = "zxcvbnm";
        for(char &ch:s1) mp[tolower(ch)] = 1;
        for(char &ch:s2) mp[tolower(ch)] = 2;
        for(char &ch:s3) mp[tolower(ch)] = 3;
        
        for(string &s:words){
            int row = mp[tolower(s[0])];
            bool flag = true;
            for(char &ch:s){
                if(mp[tolower(ch)] != row){
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(s);
        }
        return ans;
    }
};