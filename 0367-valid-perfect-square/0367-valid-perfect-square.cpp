class Solution {
public:
    bool isPerfectSquare(int num) {
        //for small input
        // for(int i = 1; i<=num; i++){
        //     if(num == i*i) return true;
        // }
        // return false;

        //large input
        if(num<2) return true;
        long long left = 2;
        long long right = num/2;
        while(left <= right){
            long long mid = left + (right-left)/2;
            if(mid*mid == num) return true;
            else if(mid*mid < num) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};