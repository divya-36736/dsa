class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n  = cardPoints.size();
        //brute force
        // //split right and left sum
        // int best = 0;

        // // try all splits: i cards from left, (k-i) cards from right
        // for(int i = 0; i <= k; i++){
        //     int sum = 0;

        //     // take i cards from left
        //     for(int j = 0; j < i; j++){
        //         sum += cardPoints[j];
        //     }

        //     // take (k-i) cards from right
        //     for(int j = 0; j < k - i; j++){
        //         sum += cardPoints[n - 1 - j];
        //     }

        //     best = max(best, sum);
        // }

        // return best;

        //optimal
        int lsum =0;
        int rsum = 0;
        int maxsum = 0;
        for(int i = 0; i<k; i++){
            lsum += cardPoints[i];
        }
        maxsum = lsum;
        int rIndx = n-1;
        for(int i = k-1; i>=0; i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[rIndx];
            rIndx--;
            maxsum = max(maxsum, lsum + rsum);
        }
        
        return maxsum;
    }
};