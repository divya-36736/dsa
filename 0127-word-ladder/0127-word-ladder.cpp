class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //in this we do BFS traversing bcz we check all the
        //alphabets and if that word match then we add them in queue

        queue<pair<string, int>>q; //jisme word and transition 
        //to reach that word store
        //in bfs traversal we push the word
        //after all transformation we got the word that match 
        //in wordlist  we add this in queue
        q.push({beginWord, 1});
        //push all word from wordlist in set 
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord); //hit tha word usko erase kr rhe ahi

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            //if word is end owrd 
            if(word == endWord) return steps;
            //word hat
            for(int i = 0; i<word.size(); i++){
                // Now, replace each character of ‘word’ with char
                // from a-z then check if ‘word’ exists in wordList.
                char original = word[i];
                for(char ch = 'a'; ch<='z'; ch++){
                    word[i] = ch;
                    // check if it exists in the set and push 
                    //it in the queue.
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;

    }
};