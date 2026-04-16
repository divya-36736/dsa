class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        unordered_map<int, int>mp;
        for(int i =0; i<n; i++){
            mp[tasks[i]]++;
        }
        int rnd = 0;

        for(auto it: mp){
            if(it.second <= 1) return -1;
            if(it.second <= 3) rnd++;
            else{
                rnd += it.second/3;
                if(it.second%3 != 0) rnd = rnd+1;
            }
        }
        return rnd;
    }
};