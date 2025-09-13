class Solution {
public:
    int maxFreqSum(string s) {
        int n = s.size();
        int maxfreq1 = 0; // for vowels
        int maxfreq2 = 0; // for consonants

        unordered_map<char,int> mp;
        for(int i = 0; i < n; i++){
            mp[s[i]]++;
        }

        for(auto it : mp){
            if(it.first == 'a' || it.first == 'e' || it.first == 'i' 
               || it.first == 'o' || it.first == 'u'){
                maxfreq1 = max(maxfreq1, it.second);
            } else {
                maxfreq2 = max(maxfreq2, it.second);
            }
        }

        return maxfreq1 + maxfreq2;
    }
};
