class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int ans = INT_MAX;
        for(int target = 1; target<=6; target++){
            int rotTop = 0;
            int rotBottom = 0;
            bool possible = true;

            for(int i = 0; i<n; i++){
                if(tops[i] != target && bottoms[i] != target){
                    possible = false;
                    break;
                }
                if(tops[i] != target) rotTop++;
                if(bottoms[i] != target) rotBottom++;
            }
            if (possible) ans = min(ans, min(rotTop, rotBottom));
        }
        return ans == INT_MAX ? -1 : ans;
    }
};