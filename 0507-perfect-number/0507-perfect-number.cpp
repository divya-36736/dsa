class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        // for(int i = 1; i<num; i++){
        //     if(num %i == 0){
        //         sum += i;
        //     }
        // }
        int i = 1;
        while(num>0 && i<num){
            if(num % i == 0){
                sum += i;
            }
            i++;
        }
        return (sum == num);
    }
};