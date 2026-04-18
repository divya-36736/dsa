class Solution {
public:
    int mirrorDistance(int n) {
        int original = n;
        int num =0;
        while(n){
            num = num*10 + n%10;
            n = n/10; 
        }
        return abs(original - num);
    }
};