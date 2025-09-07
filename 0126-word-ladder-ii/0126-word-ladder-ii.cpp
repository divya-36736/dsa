// class Solution {
// public:
//     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//         unordered_set<string> st(wordList.begin(), wordList.end());
//         vector<vector<string>> ans;
//         if (st.find(endWord) == st.end()) return ans; // endWord not in list

//         // For BFS
//         queue<vector<string>> q; 
//         q.push({beginWord});
        
//         // Track visited at current level
//         unordered_set<string> visited;
//         int level = 1;
//         int minLevel = INT_MAX;

//         while (!q.empty()) {
//             vector<string> path = q.front();
//             q.pop();

//             // If path length exceeds, reset visited
//             if (path.size() > level) {
//                 for (auto &w : visited) st.erase(w);
//                 visited.clear();
//                 level = path.size();
//                 if (level > minLevel) break; // already found shortest
//             }

//             string word = path.back();
//             if (word == endWord) {
//                 minLevel = level;
//                 ans.push_back(path);
//             }

//             // Generate neighbors
//             for (int i = 0; i < word.size(); i++) {
//                 string temp = word;
//                 for (char ch = 'a'; ch <= 'z'; ch++) {
//                     temp[i] = ch;
//                     if (st.find(temp) != st.end()) {
//                         vector<string> newPath = path;
//                         newPath.push_back(temp);
//                         q.push(newPath);
//                         visited.insert(temp);
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        vector<vector<string>> ans;
        if (st.find(endWord) == st.end()) return ans;

        // distance map: word -> min steps from beginWord
        unordered_map<string, int> dist;
        dist[beginWord] = 0;

        // parent graph: word -> all previous words in shortest path
        unordered_map<string, vector<string>> parent;

        queue<string> q;
        q.push(beginWord);
        bool found = false;
        int level = 0;

        while (!q.empty() && !found) {
            int sz = q.size();
            level++;
            unordered_set<string> visitedThisLevel;

            for (int i = 0; i < sz; i++) {
                string word = q.front();
                q.pop();

                string temp = word;
                for (int j = 0; j < temp.size(); j++) {
                    char original = temp[j];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == original) continue;
                        temp[j] = ch;

                        if (st.find(temp) != st.end()) {
                            if (!dist.count(temp)) {
                                dist[temp] = level;
                                q.push(temp);
                                visitedThisLevel.insert(temp);
                            }
                            if (dist[temp] == level) {
                                parent[temp].push_back(word);
                            }
                            if (temp == endWord) found = true;
                        }
                    }
                    temp[j] = original;
                }
            }

            // remove words of this level from dict
            for (auto &w : visitedThisLevel) st.erase(w);
        }

        if (!found) return ans;

        vector<string> path{endWord};
        backtrack(endWord, beginWord, parent, path, ans);
        return ans;
    }

private:
    void backtrack(string word, string beginWord,
                   unordered_map<string, vector<string>>& parent,
                   vector<string>& path, vector<vector<string>>& ans) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }
        for (auto &p : parent[word]) {
            path.push_back(p);
            backtrack(p, beginWord, parent, path, ans);
            path.pop_back();
        }
    }
};
