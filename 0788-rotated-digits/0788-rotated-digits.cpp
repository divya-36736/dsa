class Solution {
public:
    bool isGood(int i){
        bool changed = false;
        while(i>0){
            int d = i%10;
            if(d == 3 || d == 4 || d == 7) return false;
            if(d == 5 || d == 2 || d == 6 || d == 9){
                changed = true;
            }
            i /= 10;
        }
        return changed;
    }

    int rotatedDigits(int n) {
        int cnt  = 0;
        for(int i = 1; i<=n; i++){
            if(isGood(i)) cnt++;
        }
        return cnt;
    }
};