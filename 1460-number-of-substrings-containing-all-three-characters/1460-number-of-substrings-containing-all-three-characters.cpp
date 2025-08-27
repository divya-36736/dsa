class Solution {
public:
    // bool isPresent(string &substr){

    //     int n = substr.size();
    //     vector<int>abc(3, 0);
    //     for(char c: substr){
    //         if(c == 'a') abc[0] = 1;
    //         if(c == 'b') abc[1] = 1;
    //         if(c == 'c') abc[2] = 1;
    //     }
    //     return abc[0] && abc[1] && abc[2];
    // }

    int numberOfSubstrings(string s) {
        int n = s.size();
        //brute force approach
        // int cnt = 0;
        // for(int i = 0; i<n; i++){
        //     string substr = "";
        //     for(int j = i; j<n; j++){
        //         substr.push_back(s[j]);
        //         if(isPresent(substr)){
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;

        // vector<int>lastseen(3, -1);
        // int cnt  = 0;
        // for(int i = 0; i<n; i++){
        //     lastseen[s[i]-'a'] = i;
        //     if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1){
        //         cnt = cnt+ (1 + min(lastseen[0], min(lastseen[1], lastseen[2])));
        //     }
        // }
        // return cnt;

        int l = 0;
        int r = 0;
        int res = 0;
        vector<int>abc(3, 0);
        for(int i = 0; i<n; i++){
            abc[s[i]-'a']++;

            while(abc[0]>0 && abc[1]>0 && abc[2]>0){
                res += n - i; // all substrings starting at left and ending ≥ right
                abc[s[l] - 'a']--;
                l++;
            }
        }
        return res;
    }
};