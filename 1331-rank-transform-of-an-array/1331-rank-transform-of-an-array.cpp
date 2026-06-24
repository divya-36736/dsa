class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int>sorted = arr;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int>rankmap;
        int rank = 1;

        for(auto &nums:sorted){
            if(rankmap.find(nums) == rankmap.end()){
                rankmap[nums] = rank;
                rank++;
            }
        }

        vector<int>res;
        for(auto &nums: arr){
            res.push_back(rankmap[nums]);
        }
        return res;
    }
};