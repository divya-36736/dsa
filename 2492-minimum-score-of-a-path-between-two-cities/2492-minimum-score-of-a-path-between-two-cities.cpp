class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>>adj(n+1);
        for(auto &it: roads){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        queue<int>q;
        vector<int>vis(n+1, 0);
        q.push(1);
        vis[1] = 1;

        int ans = INT_MAX;

        while(!q.empty()){
            int it = q.front();
            q.pop();

            for(auto &nbr: adj[it]){
                int adjnode = nbr.first;
                int adjwt = nbr.second;

                ans = min(ans, adjwt);

                if(!vis[adjnode]){
                    vis[adjnode] = 1;
                    q.push(adjnode);
                }
            }
        }
        return ans;
    }
};