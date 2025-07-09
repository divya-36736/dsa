class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        reverse(citations.begin(), citations.end());
        int n = citations.size();
        int count = 0;
        
        for(int i = 0; i<n; i++){
            if(citations[i] >= i+1){
                count = i+1;
            }else{
                break;
            }
        }
        return count;
    }
};