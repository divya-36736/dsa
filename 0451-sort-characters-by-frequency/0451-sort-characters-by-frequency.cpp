class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        vector<pair<char, int>>vec;

        for(char c:s){
            bool found = false;
            for(auto &p : vec){
                if(p.first == c){
                    p.second++;
                    found = true;
                    break;
                }
            }
            if(!found){
                vec.push_back({c, 1});
            }
        }
        //sort
        sort(vec.begin(), vec.end(), [](auto &a, auto &b){
            return a.second>b.second;
        });
        string ans;
        for(auto p : vec){
            ans.append(p.second, p.first);
        }
        return ans;
    }
};