class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int n = word.size();
        int i;
        int j = 0; // for cnt
        for(i = 1; i<n;){
            if(word[i] == word[i-1] || abs(word[i] - word[i-1]) == 1){
                j++;
                i+=2;
            }
            else{
                i++;
            }
        }
        return j;
    }
};