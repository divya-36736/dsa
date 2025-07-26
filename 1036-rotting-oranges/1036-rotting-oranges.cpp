class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); //row
        int m = grid[0].size() ;// colom;
        int days = 0, fresh = 0, cnt = 0;

        queue<pair<int, int>>rotten; //position(x,y)
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] != 0) fresh++;
                if(grid[i][j] == 2) rotten.push({i,j});
            }
        }

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};

        //bfs traversing
        while(!rotten.empty()){
            int k = rotten.size();
            cnt += k;

            while(k--){
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();
                for(int i = 0; i<4; i++){
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if(nx<0 || ny<0 || nx>=n || ny>=m|| grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2;
                    
                    rotten.push({nx, ny});
                }
            }
            if(!rotten.empty()) days++;
        }
         return fresh == cnt ? days : -1;

    }
};