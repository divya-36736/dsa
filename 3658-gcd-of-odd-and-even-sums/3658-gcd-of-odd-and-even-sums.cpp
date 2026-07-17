class Solution {
public:
    int gcd(int a, int b){
        while(a>0 && b>0){
            if(a>b){
                a = a%b;
            }else{
                b = b%a;
            }
        }
        if(a == 0) return b;
        return a;
        
    }
    int gcdOfOddEvenSums(int n) {
        int cnt = 0;
        int sumodd = 0;
        int sumeven = 0;
        int j = 1;

        while(cnt< 2*n){
            if(j%2 == 0){
                sumeven += j;
            }
            else{
                sumodd += j;
            }
            cnt++;
            j++;
        }
        return gcd(sumodd, sumeven);
    }
};