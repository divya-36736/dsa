class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        int od = order.size();
        int f  = friends.size();
        vector<int>ans;
        unordered_map<int, int>mp;
        for(int &f: friends){
            mp[f]++;
        }
        for(int i = 0; i<od; i++){
            if(mp.find(order[i]) != mp.end()){
                ans.push_back(order[i]);
            }
        }
        return ans;
    }
};