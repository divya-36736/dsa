class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> dup = arr;
        sort(dup.begin(), dup.end());

        unordered_map<int,int> rank;
        int r = 1;

        for(int i = 0; i < n; i++){
            if(rank.find(dup[i]) == rank.end()){
                rank[dup[i]] = r++;
            }
        }

        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = rank[arr[i]];  
        }
        return ans;
    }
};
