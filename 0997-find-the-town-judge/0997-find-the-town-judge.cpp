class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //it should be done by indegree
        if(trust.size() == 0 && n == 1) return 1;
        vector<int>countdegree(n+1);

        for(auto person: trust){
            countdegree[person[0]]--;
            countdegree[person[1]]++;
        }

        for(int person = 0; person<countdegree.size(); person++){
            if(countdegree[person] == n-1) return person;
        }
        return -1;
    }
};