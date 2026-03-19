class Solution {
public:
    bool canpick(vector<int>&price, int k, int mid){
        int cnt = 1; //1 will be already picked up
        int last = price[0];
        for(int i = 1; i<price.size(); i++){
            if(price[i] - last >= mid){
                cnt++;
                last = price[i];
            }
            if(cnt >= k) return true;
        }
        return false;
    }
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(price.begin(), price.end());
        int low = 0;
        int high = price[n-1] - price[0];
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;

            if(canpick(price, k, mid)){
                ans = mid;
                low = mid +1;
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }
};