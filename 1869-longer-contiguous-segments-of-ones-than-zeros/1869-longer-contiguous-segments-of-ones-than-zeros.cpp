class Solution {
public:
    bool checkZeroOnes(string s) {
        int n = s.size();
        int z = 0;
        int o = 0;
        int maxio = 0;
        int maxiz = 0;
        int i;
        for(i = 0; i<n; ){
            while(s[i] == '1'){
            o++;
            i++;
            maxio = max(maxio, o);
            z = 0;
        }
        while(s[i] == '0'){
            z++;
            i++;
            maxiz = max(maxiz, z);
            o = 0;
        }
        }
        
        return maxio>maxiz;
    }
};