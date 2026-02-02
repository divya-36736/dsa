class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int targetInd = target - 'a';
        for(char c: letters){
            int ind = c - 'a';
            if(ind > targetInd){
                return c;
                break;
            }
        }
        return letters[0];
    }
};