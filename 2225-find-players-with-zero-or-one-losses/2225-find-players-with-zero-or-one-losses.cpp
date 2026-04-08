class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        unordered_map<int,int>mp ;
        for (auto it : matches){
            // winner
            if (!mp.count(it[0]))
            mp[it[0]] = 0;
            // loser
            mp[it[1]]++;
        }

        vector<int>win;
        vector<int>lost;
        

        for(auto it : mp){
            if (it.second == 0) win.push_back(it.first);
            if (it.second == 1) lost.push_back(it.first);
        }
        sort(win.begin() ,win.end());
        sort(lost.begin() ,lost.end());
        
        vector<vector<int>>ans ;
        ans.push_back(win);
        ans.push_back(lost);

        return ans ;


    }
};