class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        queue<pair<int, int>>q;
        q.push({sr, sc});
        int scolor = image[sr][sc];
        image[sr][sc] = color;
        

        if(scolor == color) return image;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(int i = 0; i<4; i++){
                int nx = x+dx[i], ny = y+dy[i];

                if(nx<0 || ny<0 || nx>=m || ny>=n || image[nx][ny] != scolor) continue;
                image[nx][ny] = color;
                q.push({nx, ny});
            }
        }
        return image;
    }
};