class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int minop = INT_MAX;
        int l = 0;
        int white = 0;

        for(int r = 0; r < n; r++){
            if(blocks[r] == 'W') white++;

            // shrink if window > k
            if(r - l + 1 > k){
                if(blocks[l] == 'W') white--;
                l++;
            }
            
            if(r - l + 1 == k){
                minop = min(minop, white);
            }
        }
        return minop;
    }
};