class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        vector<long long>store;
        int i = 0;
        int j = 1;
        
        while(store.size()<k){
            if(i<n && arr[i] == j){
                   i++;
            }else{
                store.push_back(j);
            }
            j++;
        }
        return store[k-1];
    }
};