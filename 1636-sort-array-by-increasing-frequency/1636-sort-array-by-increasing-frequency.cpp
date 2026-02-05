class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<pair<int,int>> mp;

        
        for (int num : nums) {
            bool found = false;
            for (auto &p : mp) {   
                if (p.first == num) {
                    p.second++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                mp.push_back({num, 1});
            }
        }

        sort(mp.begin(), mp.end(), [](auto &a, auto &b) {
            if (a.second == b.second)
                return a.first > b.first;
            return a.second < b.second;
        });


        vector<int> ans;
        for (auto &p : mp) {
            for (int i = 0; i < p.second; i++) {
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};
