class Solution {
public:
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return true;
        }
        return false;
    }
    long long countVowels(string word) {
        //we do this that all vowels how much times appear in any substring
        //so this we can solve (n-i)*(i+1);
        int n = word.size();
        long long cnt = 0;
        for(int i = 0; i<n ;i++){
            if(isVowel(word[i])){
                cnt += 1ll * (n-i)*(i+1);
            }
        }
        return cnt;
    }
};