class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int c = s.size();
        int cnt = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0;
        int j = 0;
        while(i<n && j<c){
            if(s[j]>=g[i]){
                i++;
                j++;
                cnt++;
            }else{
                j++;
            }
        }
        return cnt;
    }
};