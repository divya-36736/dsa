class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int c = capacity.size();
        int mini = INT_MAX;
        int ans = -1;
        for(int i = 0; i<c; i++){
            if(capacity[i] >= itemSize){
                mini = min(mini, capacity[i]);
            }
        }
        for(int i = 0; i<c; i++){
            if(mini == capacity[i]){
                ans = i;
                break;
            }
        }
        return ans;
    }
};