class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        unordered_map<char, int>mp;
        int req = 0;
        for(char &c: t){
            mp[c]++;
            req++;
        }
        int minwindowsize = INT_MAX;
        int st = 0;

        int i = 0;
        int j = 0;
        while(j<n){
            char ch = s[j];

            if(mp[ch] > 0) req--;

            mp[ch]--;
            while(req == 0){
                int currsize = j-i+1; 
                if(minwindowsize > currsize){
                    minwindowsize = currsize;
                    st = i;
                } 
                mp[s[i]]++; //shrinking
                if(mp[s[i]] > 0){
                    req++;
                }  
                i++;     
            }
            j++;
        }
        return minwindowsize == INT_MAX? "":s.substr(st, minwindowsize);
    }
};