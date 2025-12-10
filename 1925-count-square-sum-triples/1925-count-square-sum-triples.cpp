class Solution {
public:
    int countTriples(int n) {
        int cnt  = 0;
        for(int i = 1; i<n; i++){
            for(int j = i+1; j<n; j++){
                double k = sqrt(i*i + j*j);
                if(k <= n && k == (int)k) cnt += 2;
            }
        }
        return cnt;
    }
};

