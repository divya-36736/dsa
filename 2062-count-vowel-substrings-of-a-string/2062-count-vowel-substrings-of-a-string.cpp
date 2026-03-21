class Solution {
public:
    bool isVowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }

    int solve(string word, int k){
        int n = word.size();
        int l = 0, r = 0, count = 0;
        unordered_map<char, int> freq;

        while(r < n){
            if(!isVowel(word[r])){
                freq.clear();
                l = r + 1;
                r++;
                continue;   
            }

            freq[word[r]]++;

            while(freq.size() > k){
                freq[word[l]]--;
                if(freq[word[l]] == 0) freq.erase(word[l]);
                l++;
            }

            count += (r - l + 1);
            r++;
        }
        return count;
    }

    int countVowelSubstrings(string word) {
        return solve(word, 5) - solve(word, 4);
    }
};