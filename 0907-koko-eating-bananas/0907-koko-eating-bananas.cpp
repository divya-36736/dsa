#include <cmath> 

class Solution {
public:
    // return hours as long long to avoid overflow
    static long long calculateTotalHours(const vector<int>& piles, long long k) {
        long long totalh = 0;
        for (int p : piles) {
            totalh += (p + k - 1) / k; // integer ceil
        }
        return totalh;
    }
    
    //calculate maximum
    int findmax(vector<int>&piles){
        int n= piles.size();
        int maxi = INT_MIN;
        for(int i = 0; i<n; i++){
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    //calculate total hours to eat piles[i];
    // int calculateTotalHours(vector<int>&piles, long long k){
    //     long long totalh = 0;
    //     int n= piles.size();
    //     for (int p : piles) {
    //         // integer ceil(p / k)
    //         totalh += (p + k - 1) / k;
    //     }
    //     return (int)totalh;
    // }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        // int maxi = findmax(piles);
        
        // for(int i = 1; i <= maxi; i++){ 
        //     int reqTime = calculateTotalHours(piles, i);
        //     if(reqTime <= h){
        //         return i;
        //     }
        // }
        // return maxi;

        //bs
        long long low = 1;
        long long high = findmax(piles);

        while(low<=high){
            long long mid = low+(high-low)/2;
            long long totalh = calculateTotalHours(piles, (int)mid);

            if(totalh <= h){
                high = mid - 1;
                
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};
