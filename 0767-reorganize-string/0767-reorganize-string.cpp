class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char, int>mp;
        for(char &it: s){
            mp[it]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto &it: mp){
            pq.push({it.second, it.first});
        }

        pair<int, char>prev = {0, '#'};
        string str = "";
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            str += it.second;
            it.first--;

            if(prev.first > 0){
                pq.push(prev);
            }

            prev = {it.first, it.second};
        }
        if(prev.first>0){
            return "";
        }
        return str;
    }
};