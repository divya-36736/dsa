class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        //using priority queues 
        //using min heap for ascending
        //using max heap for decending
        int n = grid.size();
        int m = grid[0].size();
        unordered_map<int, priority_queue<int>>maxHeap;
         unordered_map<int, priority_queue<int, vector<int>, greater<int>>> minHeap;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int diff = i - j;
                if(diff < 0){
                    minHeap[diff].push(grid[i][j]);
                }else{
                    maxHeap[diff].push(grid[i][j]);
                }
            }
        }

        for(int i= 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int diff = i-j;
                if(diff < 0){
                    grid[i][j] = minHeap[diff].top();
                    minHeap[diff].pop();
                }else{
                    grid[i][j] = maxHeap[diff].top();
                    maxHeap[diff].pop();
                }
            }
        }
        return grid;
    }
};