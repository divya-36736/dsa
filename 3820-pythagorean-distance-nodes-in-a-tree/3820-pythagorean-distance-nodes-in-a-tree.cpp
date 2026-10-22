class Solution {
public:
    vector<int>bfs(int st, vector<vector<int>>&adj, int n){
        vector<int>dist(n, -1);
        queue<int>q;
        q.push(st);
        dist[st] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto nei:adj[node]){
                if(dist[nei] == -1){
                    dist[nei] = dist[node]+1;
                    q.push(nei);
                }
            }
        }
        return dist;
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
       vector<vector<int>>adj(n);
       for(auto&e:edges){
        int u = e[0];
        int v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
       } 

       vector<int>dx = bfs(x, adj, n);
       vector<int>dy = bfs(y, adj, n);
       vector<int>dz = bfs(z, adj, n);

       int cnt  = 0;

       for(int i = 0; i<n; i++){
        vector<int>d = {dx[i], dy[i], dz[i]};
        sort(d.begin(), d.end());

        long long a = d[0];
        long long b = d[1];
        long long c = d[2];

        if(a*a + b*b == c*c) cnt++;
       }
       return cnt;
    }
};