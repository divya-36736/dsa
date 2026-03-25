class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        int l = left;
        int r = right;
        while(l < r){
            l >>= 1;
            r >>= 1;
            shift++;
        }
        return l<<shift;
    }
};