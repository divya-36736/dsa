class Solution {
public:
    void dfs(int node, vector<vector<int>>&adj, vector<int>&visited, int &cnt){
        visited[node] = 1;
        cnt++;

        for(auto it: adj[node]){
            if(!visited[it]){
                dfs(it, adj, visited, cnt);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        //(x1​−x2​)2+(y1​−y2​)2≤r2

        vector<vector<int>>adj(n);

        for(int i = 0; i<n; i++){
            long long x1 = bombs[i][0];
            long long y1 = bombs[i][1];
            long long r = bombs[i][2];

            for(int j = 0; j<n; j++){

                if(j == i) continue;

                long long x2 = bombs[j][0];
                long long y2 = bombs[j][1];

                long long dx = x2-x1;
                long long dy = y2-y1;

                long long dist = dx*dx+dy*dy;

                if(dist <= r*r){
                    adj[i].push_back(j);
                }
            }
        }
        int maxi = 0;
        for(int i = 0; i<n; i++){
            vector<int>visited(n, 0);
            int cnt = 0;

            dfs(i, adj, visited, cnt);

            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};