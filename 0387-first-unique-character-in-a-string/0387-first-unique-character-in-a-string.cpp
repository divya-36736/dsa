class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        // unordered_map<char, int>m;
        // for(char c: s){
        //     m[c]++;
        // }
        // for(int i = 0; i<s.size(); i++){
        //     if(m[s[i]] == 1){
        //         return i;
        //     }
            
        // }
        // return -1;
        queue<int>q;
        unordered_map<char, int>m;
        for(int i = 0; i<n; i++){
            if(m.find(s[i]) == m.end()){
                q.push(i);
            }
            m[s[i]]++;
        }
            while(q.size()>0 && m[s[q.front()]] > 1){
                q.pop();
            }
            return q.empty() ? -1 : q.front();
    }
};