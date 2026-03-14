class Solution {
public:
    int bitwiseComplement(int n) {
        //by masking approach
        //mask = 111.. length as the length of n in binary
        if(n == 0) return 1;
        int mask = 0;
        int temp = n;
        while(temp>0){
            mask = (mask << 1) | 1;
            temp >>= 1;
        }
        return n ^ mask;
    }
};