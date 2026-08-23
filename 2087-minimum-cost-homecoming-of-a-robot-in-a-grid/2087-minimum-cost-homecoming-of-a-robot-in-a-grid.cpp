class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int sr = startPos[0];
        int sc = startPos[1];
        int hr = homePos[0];
        int hc = homePos[1];
        int ans = 0;
        while(sr<hr){
            sr++;
            ans += rowCosts[sr];
        }

        while(sr>hr){
            sr--;
            ans += rowCosts[sr];
        }

        while(sc<hc){
            sc++;
            ans += colCosts[sc];
        }
        while(sc>hc){
            sc--;
            ans += colCosts[sc];
        }
        return ans;
    }
};