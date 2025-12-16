class Solution {
public:
    bool isMirror(char &c1, char &c2) {
        // 'a' + 'z' = 219 (ASCII)
        return (c1 + c2) == ('a' + 'z');
    }
    long long calculateScore(string s) {
        int n = s.size();
        long long sum = 0;
        vector<vector<int>> pos(26);
        for(int i = 0; i<n; i++){
           int c = s[i] - 'a';
           int mirror = 25 - c;
           if(!pos[mirror].empty()){ //if empty then we mark it
            int j = pos[mirror].back();
            pos[mirror].pop_back();
            sum += (i-j);
           }else{
            pos[c].push_back(i);
           }
        }
        return sum;
    }
};