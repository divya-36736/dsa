class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;
        int mod = 1e9+7;
        int even = 1;
        int odd = 0;
        int sum = 0;
        for(int x: arr){
            sum = (sum+x)%mod;
            if(sum %2 ==1){
                cnt = (cnt+even)%mod;
                odd++;
            }else{
                cnt = (cnt+odd)%mod;
                even++;
            }
        }
        return cnt;
    }
};