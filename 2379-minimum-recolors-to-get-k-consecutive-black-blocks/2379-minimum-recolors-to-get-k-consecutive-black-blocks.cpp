class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int minop = INT_MAX;
        for(int i = 0; i<=n-k; i++){
            int white = 0;
            for(int j = i; j<i+k; j++){
                if(blocks[j] == 'W') white++;
            }
            minop = min(minop, white);
        }
        return minop;
    }
};