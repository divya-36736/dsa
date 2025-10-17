// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // long long mini = INT_MAX;
        // for(long long i = 1; i<=n; i++){
        //     if(isBadVersion(i)){
        //         mini = min(mini,i);
        //     }
        // }
        // return mini;
        int st = 1;
        int end = n;
        int mini = INT_MAX;
        while(st<=end){
            int mid = st + (end - st)/2;
            if(isBadVersion(mid)){
                mini = min(mini, mid);
                end = mid-1;
            }else{
                st = mid+1;
            }
        }
        return mini;
    }
};