class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int total = n*n;
        vector<int>freq(total+1, 0);
        vector<int>ans;
        
        // sort(grid.begin(), grid.end());
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                freq[grid[i][j]]++;
            }
        }
        int repeated = -1, missing = -1;
        for(int i = 1; i<=total; i++){
            if(freq[i] == 2) repeated=i;
            else if(freq[i] == 0) missing =i;
        }
        ans.push_back(repeated);
        ans.push_back(missing);
        return ans;
    }
};