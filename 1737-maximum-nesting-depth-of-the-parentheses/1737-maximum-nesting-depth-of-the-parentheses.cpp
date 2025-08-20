class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int maxDepth = 0;
        int currDepth = 0;
        for(char c : s){
            if(c == '('){
                currDepth++;
                maxDepth = max(maxDepth, currDepth);
            }
            else if(c == ')'){
                currDepth--;
            }
        }
        return maxDepth;
    }
};