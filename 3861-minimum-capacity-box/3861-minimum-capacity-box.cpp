class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int c = capacity.size();
        int mini = INT_MAX;
        int ans = -1;
        for(int i = 0; i<c; i++){
            if(capacity[i] >= itemSize){
                if(capacity[i] < mini){
                    mini = min(mini, capacity[i]);
                    ans = i;
                }
            }
        }
        if(ans == c)return -1;
        return ans;
    }
};