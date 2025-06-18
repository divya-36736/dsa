class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        
        for(int i = 0; i<=n; i++){
            int count = 0;
            int x = i;
            while(x>0){
                int r = x%2;
                if(r == 1) count++;
                x = x/2;
            }
            ans.push_back(count);
        }
        return ans;
    }
};