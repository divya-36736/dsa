class Solution {
public:
    unordered_map<int, int>mp;
    map<pair<int, int>, bool>dp;

    bool memo(int i, int lastjump, vector<int>&stones){
        int n = stones.size();
        if(i == n-1) return true;

        //if already exit then return
        if(dp.count({i, lastjump})) return dp[{i, lastjump}];
        //otherwise we create
        for(int jump = lastjump-1; jump<=lastjump+1; jump++){
            if(jump<=0) continue;

            int nextpos = stones[i]+jump;

            if(mp.count(nextpos)){
                int nextIndx = mp[nextpos];
                if(memo(nextIndx, jump, stones)) return dp[{i, lastjump}] =true;
            }
        }
        return dp[{i, lastjump}] = false;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        
        if(stones[1] != 1) return false;

        for(int i = 0; i<n; i++){
            mp[stones[i]] = i;
        }
        return memo(1, 1, stones);
    }
};