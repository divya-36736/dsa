class Solution {
public:
    int distinctIntegers(int n) {
        int cnt = 0;
        
        unordered_set<int>st;
        if(n == 1 || n==2) st.insert(n);
        for(int i = n; i>=2; i--){
            for(int j = 2; j<=n; j++){
                if(i%j == 1){
                    st.insert({i,j});
                    cnt++;
                }
            }
        }
        //return cnt;
        return st.size();
    }
};