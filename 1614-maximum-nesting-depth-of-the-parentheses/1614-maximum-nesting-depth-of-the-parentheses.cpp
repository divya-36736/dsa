class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        long long cnt = 0;
        int i = 0;
        long long ans = 0;
        while(i<n){
            if(s[i] == '('){
                cnt++;
            }
            else if(s[i] == ')'){
                cnt--;
            }
            ans = max(ans, cnt);
            i++;
        }
        return ans;
    }
};