class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>>pq;

        vector<vector<int>>dist(n, vector<int>(m, 1e9));
        pq.push({grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, -1, 0, 1};

        while(!pq.empty()){
            auto it = pq.top();
            int time = it.first;
            int r = it.second.first;
            int c = it.second.second;
            pq.pop();

            if(r == n-1 && c == m-1) return time;

            for(int i = 0; i<4; i++){
                int newr = r + dx[i];
                int newc = c + dy[i];
                if(newr >= 0 && newc>=0 && newr<n && newc<m){
                    int newtime = max(time, grid[newr][newc]);
                    if(newtime < dist[newr][newc]){
                        dist[newr][newc] = newtime;
                        pq.push({dist[newr][newc], {newr, newc}});
                    }
                }
            }
        }
        return -1;
    }
};