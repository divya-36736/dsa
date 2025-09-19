// class Solution {
// public:
//     int arrangeCoins(int n) {
//         if(n==1) return 1;
//         int row =1;
//         int cnt = 0;
//         int coins = n;
//         while(row<n){
//                 coins = coins-row;
//                 if(coins<0){
//                     break;
//                 }else{
//                     cnt++;
//                 }
//             row++;
//         }
//         return cnt;
//     }
// };

class Solution {
public:
    long long sum(long long m){
        return m*(m+1)/2;
    }
    int arrangeCoins(int n) {
        long long m;
        long long s=1;
        long long e=n;
        int index=0;
        while(s<=e){
             m=s+(e-s)/2;
            long long ans=sum(m);
            if(ans<=n){
                index=m;
                s=m+1;
            }
            else if(ans>n){
                e=m-1;
            }
        }
        return index;
    }
};