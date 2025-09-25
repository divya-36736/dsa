class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        if(k == 0)return vector<int>(n,0);

        //duplicate array to handle circular array
        vector<int>arr(2*n);
        for(int i = 0; i<n; i++) arr[i] = arr[n+i] = code[i];

        vector<int>ans(n, 0);
        if(k>0){
            //prefix sum array
            vector<int>prefix(2*n+1, 0);
            for(int i = 0; i<2*n; i++){
                prefix[i+1] = prefix[i]+arr[i];
            }

            for(int i = 0; i<n; i++){
                ans[i] = prefix[i+1+k] - prefix[i+1]; //sum of next k numbers
            }
        }else{
            k = -k;
            //suffix sum array
            vector<int>suffix(2*n+1, 0);
            for(int i = 2*n-1; i>=0; i--) suffix[i] = suffix[i+1]+arr[i];

            for(int i = 0; i<n; i++){
                ans[i] = suffix[i+n-k] - suffix[i+n];//sum of previour k numbers
            }
        }
        return ans;
    }
};