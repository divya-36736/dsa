class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        unordered_map<int, int>win;
        unordered_map<int, int>lose;
        vector<vector<int>>ans;

        for(int i = 0; i<n; i++){
            win[matches[i][0]]++;
            lose[matches[i][1]]++;
        }
        vector<int>ans1;
        for(auto it: win){
            int winin = it.first;
            if(lose.find(winin) == lose.end()){
                ans1.push_back(winin);
            }
        }
        sort(ans1.begin(), ans1.end());
        ans.push_back(ans1);
        vector<int>ans2;
        for(auto it:lose){
            int losein = it.first;
            if(it.second == 1){
                ans2.push_back(losein);
            }
        }
        sort(ans2.begin(), ans2.end());
        ans.push_back(ans2);
        return ans;
    }
};