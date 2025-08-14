class Solution {
public:
//write static bcz when we call this in sort then then obj 
//is required but this is not good or correct method then we 
//here use static if not use static then it is non-static 
//and non static ko call krne ke liye object ki jarurat hoti hai;

    static bool cmp(pair<char, int>&a, pair<char, int>&b){
        return a.second>b.second;
    }

    string frequencySort(string s) {
        //int n = s.size();
        // unordered_map<char, int> count;
        // //stores count in map
        // for(int i = 0; i<n; i++){
        //     count[s[i]]++;
        // }
        // string ans = "";
        // for(auto it: count){
        //     int size = it.second;
        //    for(int i = 0; i<size; i++){
        //     ans += it.first;
        //    }
        // }
        // return ans;

        int n = s.size();
        unordered_map<char, int> count;

        // stores count in map
        for (int i = 0; i < n; i++) {
            count[s[i]]++;
        }

        // move (char, freq) pairs to a vector for sorting
        vector<pair<char, int>> freq(count.begin(), count.end());

        // sort by frequency in descending order
        sort(freq.begin(), freq.end(), cmp);

        string ans = "";
        // append each char freq times
        for (auto &it : freq) {
            ans.append(it.second, it.first);
        }

        return ans;
    }
};