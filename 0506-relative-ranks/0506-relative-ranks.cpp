class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string>ans;
        vector<int>sortedScore = score; //copy the score in sortedScore

        sort(sortedScore.rbegin(), sortedScore.rend());

        unordered_map<int, int>rankMap;
        int rank = 1;
        //score ko map krna rank wise
        for(int scores: sortedScore){
            rankMap[scores] = rank++;
        }

         for(int s : score){ // iterate original scores
            int r = rankMap[s];
            if(r == 1) ans.push_back("Gold Medal");
            else if(r == 2) ans.push_back("Silver Medal");
            else if(r == 3) ans.push_back("Bronze Medal");
            else ans.push_back(to_string(r));
        }

        return ans;
    }
};