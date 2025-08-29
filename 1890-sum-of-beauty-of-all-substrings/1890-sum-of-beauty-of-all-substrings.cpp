class Solution {
public:
    int beautySum(string s) {
        //btute force
        //we find all subsets and all subsets we calculate the freq, and 
        //also calculate the difference 
        int n = s.size();
        
        int ans = 0;
        for(int i = 0; i<n; i++){
            vector<int>m(26,0);
            for(int j = i; j<n; j++){
                m[s[j]-'a']++;
                int mf = 0;
                int lf = INT_MAX;
                for(int a : m){
                    if(a>0){
                    mf = max(mf, a);
                    lf = min(lf, a);
                    }
                }
                ans += (mf-lf);
            }
        }
        return ans;
    }
};