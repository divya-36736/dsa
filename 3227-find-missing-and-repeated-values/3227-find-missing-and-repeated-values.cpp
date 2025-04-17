class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        // int n = grid.size();
        // int total = n*n;
        // vector<int>freq(total+1, 0);
        // vector<int>ans;
        
        // // sort(grid.begin(), grid.end());
        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<n; j++){
        //         freq[grid[i][j]]++;
        //     }
        // }
        // int repeated = -1, missing = -1;
        // for(int i = 1; i<=total; i++){
        //     if(freq[i] == 2) repeated=i;
        //     else if(freq[i] == 0) missing =i;
        // }
        // ans.push_back(repeated);
        // ans.push_back(missing);
        // return ans;

        int n = grid.size();
        vector<int>ans;
        unordered_set<int>s;
        int a,b;
        int actualSum = 0;
        int expSum = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                actualSum += grid[i][j];
                if(s.find(grid[i][j]) != s.end()){
                    a = grid[i][j];
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }
        }
        expSum = (n*n)*(n*n + 1)/2;
        b =  expSum + a - actualSum;
        ans.push_back(b);
        return ans;
    }
};