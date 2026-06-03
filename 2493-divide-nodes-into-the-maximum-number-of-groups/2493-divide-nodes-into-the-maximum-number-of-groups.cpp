class Solution {
public:
    int bfs(int i, vector<vector<int>>&adj, int n){
        vector<int>dist(n+1, -1);

        queue<int>q;
        q.push(i);
        dist[i] = 0;

        int maxdepth = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto &nbr: adj[node]){
                if(dist[nbr] == -1){
                    dist[nbr] = dist[node]+1;
                    maxdepth = max(maxdepth, dist[nbr]+1);
                    q.push(nbr);
                }
            }
        }
        return maxdepth;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        //convert it into adj list
        vector<vector<int>>adj(n+1);
        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int>color(n+1, -1);
        vector<int>bestDepth(n+1);

        for(int i = 1; i<=n; i++){
            bestDepth[i] = bfs(i, adj, n);
        }

        int ans = 0;
        for(int i = 1; i<=n; i++){
            if(color[i] != -1) continue;

            queue<int>q;
            q.push(i);
            color[i] = 0;

            int mx = 0;
            while(!q.empty()){
                int node = q.front();
                q.pop();

                mx = max(mx, bestDepth[node]);

                for(auto &nbr: adj[node]){
                    if(color[nbr] == -1){
                        color[nbr] = color[node]^1;
                        q.push(nbr);
                    }
                    else if(color[nbr] == color[node]) return -1;
                }
            }
            ans += mx;
        }
        return ans;
    }
};