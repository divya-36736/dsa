class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int cnt  = 0;
        int ans = INT_MIN;
        for(int i = 0; i<n; i++){
            if(s[i] == '(') cnt++;
            else if(s[i] == ')') cnt--;
            ans = max(ans, cnt);
        }
        return ans;
    }
};