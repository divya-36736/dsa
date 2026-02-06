class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int>>mp;
        for(int &num: nums){
            bool found = false;
            for(auto &it:mp){
                if(it.first == num){
                    it.second++;
                    found = true;
                    break;
                }
            }
            if(!found){
                mp.push_back({num,1});
            }
        }

        sort(mp.begin(), mp.end(), [](auto &a, auto &b){
            return a.second>b.second;
        });

        vector<int>ans;
        for(auto it:mp){
            if(k>0){
            ans.push_back(it.first);
            //.pop_bacK();
            k--;}
        }
        return ans;
    }
};