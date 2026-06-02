class Solution {
public:
    void backtrack(string endWord, string beginWord, unordered_map<string, vector<string>>&parent, vector<string>&path, vector<vector<string>>& ans){
        if(endWord == beginWord){
            vector<string>temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }
        for(auto &p: parent[endWord]){
            path.push_back(p);
            backtrack(p, beginWord, parent, path, ans);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(), wordList.end());
        vector<vector<string>>ans;
        if(st.find(endWord) == st.end()) return  ans;

        unordered_map<string, int>dist;
        dist[beginWord] = 0;

        unordered_map<string, vector<string>>parent;

        queue<string>q;
        q.push(beginWord);
        bool found = false;
        int level = 0;

        while(!q.empty() && !found){
            int sz = q.size();
            level++;
            unordered_set<string>visitedlevel;

            for(int i =0; i<sz; i++){
                string word = q.front();
                q.pop();

                string temp = word;
                for(int j = 0; j<temp.size(); j++){
                    char original = temp[j];
                    for(char ch = 'a'; ch<='z'; ch++){
                        if(ch == original) continue;
                        temp[j] = ch;

                        if(st.find(temp) != st.end()){
                            if(!dist.count(temp)){
                                dist[temp] = level;
                                q.push(temp);
                                visitedlevel.insert(temp);
                            }
                            if(dist[temp] == level){
                                parent[temp].push_back(word);
                            }
                            if(temp == endWord) found = true;
                        }
                    }
                    temp[j] = original;
                }
            }
            for(auto &w : visitedlevel) st.erase(w);
        }
        if(!found) return ans;
        vector<string>path{endWord};
        backtrack(endWord, beginWord, parent, path, ans);
        return ans;
    }
};