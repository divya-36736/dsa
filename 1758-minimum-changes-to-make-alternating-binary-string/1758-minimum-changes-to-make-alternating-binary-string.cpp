class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int op1 = 0, op2 = 0;

        for(int i = 0; i < n; i++){
            int bit = s[i] - '0';

            op1 += bit ^ (i % 2);       // pattern 010101...
            op2 += bit ^ (1 ^ (i % 2)); // pattern 101010...
        }

        return min(op1, op2);
    }
};