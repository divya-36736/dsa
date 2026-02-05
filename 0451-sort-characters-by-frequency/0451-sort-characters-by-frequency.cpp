class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char,int>> vec;

        // count using vector<pair>
        for (char c : s) {
            bool found = false;
            for (auto &p : vec) {
                if (p.first == c) {
                    p.second++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                vec.push_back({c, 1});
            }
        }

        // sort by frequency
        sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        // build answer
        string ans;
        for (auto &p : vec) {
            ans.append(p.second, p.first);
        }

        return ans;
    }
};
