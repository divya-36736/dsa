class Solution {
public:
    // Function to cimpute the binary refletion of a number 
    int reflect (int x){
        int rev = 0 ;
        while (x >0){
            int bit = x % 2;
            rev = rev * 2 + bit ;
            x = x/2 ;
        }
        return rev ;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<int,int>>arr;

        for (int x : nums){
            arr.push_back({reflect(x) , x});
        }

        sort(arr.begin() , arr.end() ,[&](auto &a , auto &b){
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });

        vector<int>result ;
        result.reserve(nums.size());
        for (auto &p : arr){
            result .push_back(p.second);
        }

        return result ;
    }
};