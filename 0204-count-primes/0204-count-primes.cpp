class Solution {
public:
    int countPrimes(int n) {

        if(n == 1 || n == 0) return 0;
        int count = 0;
        
        // for(int i = 2; i<n; i++){
        //     bool isPrime = true;
        //     for(int j = 2; j<i; j++){
        //         if(i%j == 0){
        //             isPrime = false;
        //             break;
        //         }
        //     }
        //     if(isPrime){
        //         count++;
        //     }
        // }
        // return count;
        vector<bool>isPrime(n+1, true);
        for(int i = 2; i<n; i++){
            if(isPrime[i]){
                count++;

                for(int j = i*2; j<n; j = j+i){
                    isPrime[j] = false;
                }
            }
        }
        return count;
    }
};