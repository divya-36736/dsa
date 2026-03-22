class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int totl = 0;
        for(int i = 0; i<k; i++){
            totl += cardPoints[i];
        }
        int j = n-1;
        int totr = 0;
        int i = k-1;
        int maxSum = totl;
        while(j>=(n-k) && i>=0){
            totr += cardPoints[j];
            totl -= cardPoints[i];
            j--;
            maxSum = max(maxSum, totr+totl);
            i--;
        }
        return maxSum;
    }
};