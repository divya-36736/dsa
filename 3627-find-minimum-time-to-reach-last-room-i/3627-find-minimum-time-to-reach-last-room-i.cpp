class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        //grapg dijkidtra algo
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> min;

        min.push({0, 0, 0});
        moveTime[0][0] = 0;

        int dx[] = {0, 1, 0, -1};
        int dy[] = {-1, 0, 1, 0};

        while(!min.empty()){
            auto current = min.top();
            min.pop();
            int currTime = current[0];
            int currRow = current[1];
            int currCol = current[2];
            if(currTime >= dist[currRow][currCol]) continue;
            if(currRow == n-1 && currCol == m-1) return currTime;
            dist[currRow][currCol] = currTime;
            //for adjacent check
            for(int i = 0; i<4; i++){
                int nRow = currRow + dx[i];
                int nCol = currCol + dy[i];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && dist[nRow][nCol] == INT_MAX){
                    int nextTime = max(moveTime[nRow][nCol], currTime) + 1;
                    min.push({nextTime, nRow, nCol});
                }
            }
        }
        return -1;
    }
};