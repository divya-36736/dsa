class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        set<vector<int>>st;
        for(int i = 0; i<n; i++){
            vector<int>temp;
            int diviP = 0;
            for(int j = i; j<n; j++){
                if(nums[j] % p == 0) diviP++;

                if(diviP > k) break;

                temp.push_back(nums[j]);
                st.insert(temp); 
            }
        }
        return st.size();
    }
};