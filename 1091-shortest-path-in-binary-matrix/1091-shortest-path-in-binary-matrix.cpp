class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(n == 1 && m ==1 && grid[0][0] == 0) return 1;
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;

        vector<vector<int>>dist(n, vector<int>(m, 1e9));
        queue<pair<int, pair<int, int>>>q;
        dist[0][0] = 1;
        q.push({1, {0, 0}});

        int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
        int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

        while(!q.empty()){
            auto it = q.front();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            q.pop();
            
            for(int i = 0; i<8; i++){
                int newr = r + dx[i];
                int newc = c + dy[i];

                if(newr>=0 && newr<n && newc >= 0 && newc<m && grid[newr][newc] == 0 && dist[newr][newc] > 1+dis){
                    dist[newr][newc] = 1 + dis;
                    if(newr == n-1 && newc == m-1) return 1+dis; 
                    q.push({1+dis, {newr, newc}});
                }
            }
        }
        return -1;
    }
};