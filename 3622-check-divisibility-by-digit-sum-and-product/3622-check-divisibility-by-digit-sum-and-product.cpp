class Solution {
public:
    bool checkDivisibility(int n) {
        int ori = n;
        int sum = 0;
        int mul = 1;
        while(n){
            sum += (n%10);
            mul *= (n%10);
            n /= 10;
        }
        if(ori % (sum + mul) == 0) return true;
        return false;
    }
};