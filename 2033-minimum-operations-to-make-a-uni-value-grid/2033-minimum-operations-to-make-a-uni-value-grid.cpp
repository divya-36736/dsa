class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> arr;
        for (auto &row : grid) {
            for (int r : row) {
                arr.push_back(r);
            }
        }
        int base = arr[0];
        for (int v : arr) {
            if (abs(v - base) % x != 0)
                return -1;
        }

        sort(arr.begin(), arr.end());

        int med = arr[arr.size() / 2];
        int ops = 0;
        for(int v:arr){
            ops += abs(v-med)/x;
        }
        return ops;
    }
};