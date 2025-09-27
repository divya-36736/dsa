class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        // vector<string>ans;
        // vector<int>sortedScore = score; //copy the score in sortedScore

        // sort(sortedScore.rbegin(), sortedScore.rend());

        // unordered_map<int, int>rankMap;
        // int rank = 1;
        // //score ko map krna rank wise
        // for(int scores: sortedScore){
        //     rankMap[scores] = rank++;
        // }

        //  for(int s : score){ // iterate original scores
        //     int r = rankMap[s];
        //     if(r == 1) ans.push_back("Gold Medal");
        //     else if(r == 2) ans.push_back("Silver Medal");
        //     else if(r == 3) ans.push_back("Bronze Medal");
        //     else ans.push_back(to_string(r));
        // }
        // return ans;
        vector<string>ans(n);

        vector<pair<int,int>> scoreIndex;
        for(int i=0;i<n;i++){
            scoreIndex.push_back({score[i], i});
        }
        //sorte by decesnding orde
        sort(scoreIndex.rbegin(), scoreIndex.rend());
        //for loop for assign rank
        for(int rank = 1; rank<=n; rank++){
            int idx = scoreIndex[rank-1].second;
            if(rank == 1) ans[idx] = "Gold Medal";
            else if(rank == 2) ans[idx] = "Silver Medal";
            else if(rank == 3) ans[idx] = "Bronze Medal";
            else ans[idx] = to_string(rank);
        }
        return ans;
    }
};