class Solution {
public:
    int hIndex(vector<int>& citations) {
        // sort(citations.begin(), citations.end());
        // reverse(citations.begin(), citations.end());
        // int n = citations.size();
        // int count = 0;
        
        // for(int i = 0; i<n; i++){
        //     if(citations[i] >= i+1){
        //         count = i+1;
        //     }else{
        //         break;
        //     }
        // }
        // return count;


        //optimal
        sort(citations.begin(), citations.end());
        reverse(citations.begin(), citations.end());
        int n = citations.size();
        int h = 0;
        int st = 0;
        int end = n-1;
        while(st<=end){
            int mid = st + (end - st)/2;
            if(citations[mid] >= mid+1){
                st = mid+1;
                h = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return h;
    }
};