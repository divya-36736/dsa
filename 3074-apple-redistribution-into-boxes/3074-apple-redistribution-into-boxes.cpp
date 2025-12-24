class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int a = apple.size();
        int c = capacity.size();
        sort(capacity.begin(), capacity.end());
        int tot_cap = 0;
        int tot_app = 0;
        for(int i = 0; i<a; i++){
            tot_app += apple[i];
        }
        int ans = 0;
        for(int i = c-1; i>=0; i--){
            tot_cap += capacity[i];
            if(tot_cap >= tot_app){
                ans = c-i;
                break;
            }
        }
        return ans;
    }
};