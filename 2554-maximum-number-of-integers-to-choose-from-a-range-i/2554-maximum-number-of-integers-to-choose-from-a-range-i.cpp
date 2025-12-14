class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        //set for dublicate skip
        unordered_set<int>bannedSet(banned.begin(), banned.end());

        long long sum = 0;
        int cnt = 0;
        for(int i = 1; i<=n; i++){
            if(bannedSet.count(i)) continue;
            sum  += i;
            if(sum > maxSum) break;
            cnt++;
        } 
        return cnt;
    }
};