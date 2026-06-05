class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>dist(n, vector<int>(m, 1e9));

        //priority_queue<int, vector<int>, greater<int>> pq;
        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>>pq;

        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, -1, 0, 1};

        while(!pq.empty()){
            int diff = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if(r == n-1 && c == m-1) return diff;

            for(int i = 0; i<4; i++){
                int newr = r+dx[i];
                int newc = c+dy[i];

                if(newr >= 0 && newr<n && newc>=0 && newc<m){
                    int neweffort = max(diff, abs(heights[newr][newc] - heights[r][c]));
                    if(neweffort < dist[newr][newc]){
                        dist[newr][newc] = neweffort;
                        pq.push({{dist[newr][newc]}, {newr, newc}});
                    }
                }
            }
        }
        return 0;
    }
};