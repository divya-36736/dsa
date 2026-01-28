class Solution {
public:
    bool ispossible(vector<int>&bloomDay, int day, int m, int k){
        int cnt = 0; //for types of flowers
        int bouquets = 0;

        for(int bloom : bloomDay){
            if(bloom <= day){
                cnt++;
                if(cnt == k){
                    bouquets++;
                    cnt = 0;
                }
            }else{
                cnt = 0;
            }
        }
        return bouquets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int b = bloomDay.size();
        long long totalflowers = 1ll *m*k;
        if(totalflowers > b){
            return -1;
        }
        int minday = *min_element(bloomDay.begin(), bloomDay.end());
        int maxday = *max_element(bloomDay.begin(), bloomDay.end());
        int st = minday;
        int end = maxday;
        int res = -1;
        while(st<=end){
            int mid = st+(end-st)/2;
            if(ispossible(bloomDay, mid, m, k)){
                res = mid;
                end = mid-1;
            }else{
                st = mid+1;
            }
        }
        return res;
    }
};