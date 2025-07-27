class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>vis(n, vector<int>(m ,0)); //visited mats
        vector<vector<int>>dist(n, vector<int>(m , 0)); //distance matrix

        //BFS traversal
        queue<pair<pair<int, int>,int>>q; //for(x,y,(dist))

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 0){  //ydi mat[i][j] == 0, toh 0 ki 0 sedistance 0 hi hogi
                    q.push({{i,j},0}); //push them in queue
                    vis[i][j] = 1;  ///visted
                }
                else{
                    vis[i][j] = 0; //ydi 0 nhi hai toh unhe unvisited hi rakhenge
                }
            }
        }

        int delrow[] = {-1, 0, 1, 0};
        int delcol[]={0, -1, 0, 1};
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int step = q.front().second;
            q.pop();
            dist[x][y] = step;

            //for check the up down left right
            for(int i = 0; i<4; i++){
                int nx  = x + delrow[i];
                int ny = y + delcol[i];

                if(nx<0 || ny<0|| nx>=n|| ny>=m ||vis[nx][ny]) continue;

                vis[nx][ny] = 1;
                q.push({{nx,ny}, step+1});

            }
        }

        return dist;
    }
};