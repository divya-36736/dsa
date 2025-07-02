class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxlen = 0;
        
        // unordered_map<char, int>m;
        // for(int i = 0; i<n; i++){
        //     m.clear();
        //     int maxfreq = 0;
        //     for(int j=i; j<n; j++){
        //         m[s[j]]++;
        //         maxfreq = max(maxfreq, m[s[j]]);
        //         int len = j-i+1;
        //         if (len - maxfreq <= k){
        //             maxlen = max(maxlen, len); 
        //         }else{
        //             break;
        //         }
        //     }

        // }
        // return maxlen;


        //optimal approach
        // int l = 0;
        // int r = 0;
        // unordered_map<char, int>m;
        // int maxfreq = 0;
        // while(r<n){
        //     m[s[r]]++;
        //     maxfreq = max(maxfreq, m[s[r]]);
        //     while((r-l+1) - maxfreq > k){
        //         m[s[l]]--;
        //         if(m[s[l]] == 0){
        //             m.erase(s[l]);
        //         }
        //         l++;
        //     }
        //     maxlen = max(maxlen, r-l+1);
        //     r++;
        // }
        // return maxlen;

        int l = 0;
        int r = 0;
        unordered_map<char, int>m;
        int maxfreq = 0;
        while(r<n){
            m[s[r]]++;
            maxfreq = max(maxfreq, m[s[r]]);
            if((r-l+1) - maxfreq > k){
                m[s[l]]--;
                if(m[s[l]] == 0){
                    m.erase(s[l]);
                }
                l++;
            }
            maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};