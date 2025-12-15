class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;

        vector<string>bin(n);

        for(int i = 0; i<3; i++){
            //binary conversion
            int x = nums[i];
            if(x == 0) bin[i]="0";
            while(x>0){
                bin[i] += to_string(x%2);
                x /= 2;
            }
            reverse(bin[i].begin(), bin[i].end());
        }
        //3 index tk traverse krne ke liye we difine a vector
        vector<int>p = {0, 1, 2};
        //do while loop for check all permutaions for 
        //maximumm value of binary
        do{
            string ans = "";
            for(int i = 0; i<n; i++){
                ans += bin[p[i]];
            }

            int ans1 = 0;
            for(char c: ans){
                ans1 = ans1*2 + (c-'0');
            }

            maxi = max(maxi, ans1);
        }while(next_permutation(p.begin(), p.end()));
        return maxi;

    }
};
