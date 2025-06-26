class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // sort(g.begin(), g.end()); 
        // sort(s.begin(), s.end()); 
        // int count = 0; 
        // int i = 0; 
        // int j = 0; 
        
        // while (i < g.size() && j < s.size()) {
        //     if (g[i] <= s[j]) { 
        //         count++; 
        //         i++;
        //         j++; 
        //     } else {
        //         j++; 
        //     }
        // }
        
        // return count;

        int n = g.size();
        int m = s.size();
        int l =0;
        int r = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(l<m && r<n){
            if(g[r] <= s[l]){
                r = r+1;
            }
            l = l+1;
        }
        return r;
    }
};