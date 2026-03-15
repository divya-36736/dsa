class Solution {
public:
    int gcd(int a, int b){
        while(a>0 && b>0){
            if(a>b){
                a = a%b;
            }
            else{
                b = b%a;
            }
        }
        if(a == 0){
            return b;
        }
        return a;
    }

    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int>mxi(n);
        vector<int>prefixGcd(n); 

        mxi[0] = nums[0];

        for(int i = 1; i<n; i++){
            mxi[i] = max(mxi[i-1], nums[i]);
        }
        for(int i = 0; i<n; i++){
            prefixGcd[i] = gcd(mxi[i], nums[i]);
        }

        sort(prefixGcd.begin(), prefixGcd.end());
        int st = 0;
        int end = prefixGcd.size()-1;
        long long sum = 0;
        while(st<end){
            sum += gcd(prefixGcd[st], prefixGcd[end]);
            st++;
            end--;
        }
        return sum;
    }
};