class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m =mat[0].size();
        queue<pair<pair<int, int>,int>>q;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        vector<vector<int>>dist(n, vector<int>(m, 0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, -1, 0, 1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int x = it.first.first;
            int y = it.first.second;
            int step = it.second;

            for(int dir = 0; dir<4; dir++){
                int nx = x+dx[dir];
                int ny = y+dy[dir];
                if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny]){
                    vis[nx][ny] = 1;
                    dist[nx][ny] = step+1;
                    q.push({{nx, ny}, step+1});
                }
            }
        }
        return dist;
    }
};