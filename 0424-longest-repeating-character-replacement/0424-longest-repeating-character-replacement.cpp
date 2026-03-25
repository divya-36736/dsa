class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;
        for(char c = 'A'; c<='z'; c++){
            int i = 0; 
            int j = 0;
            int replace = 0;
            while(j<n){
                if(s[j] == c){
                    j++;
                }
                else if(replace < k){
                    replace++;
                    j++;
                }
                else if(s[i] == c){
                    i++;
                }
                else{
                    i++; 
                    replace--;
                }
                ans = max(ans, j-i);
            }
        }
        return ans;
    }
};