class Solution {
public:
    long long calproduct(vector<int>&quantities, long long mid){
        long long store = 0;
        for(int q : quantities){
            store += (q+mid-1)/mid;
        }
        return store;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int q = quantities.size();
        int maxval = *max_element(quantities.begin(), quantities.end());
        int st = 1;
        int end = maxval;
        int res = maxval;
        while(st<=end){
            long long mid = st + (end-st)/2;
            long long store = calproduct(quantities, mid);
            if(store <= n){
                res = mid;
                end = mid - 1;
            }else{
                st = mid+1;
            }
        }
        return res;
    }
};