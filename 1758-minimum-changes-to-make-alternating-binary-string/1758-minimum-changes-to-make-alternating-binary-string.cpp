class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int op1 = 0;
        int op2 = 0;
        for(int i = 0; i<n; i++){
            if(s[i] != (i%2 ? '1':'0'))op1++;
            if(s[i] != (i%2 ? '0' : '1')) op2++;
        }
        return min(op1, op2);
    }
};