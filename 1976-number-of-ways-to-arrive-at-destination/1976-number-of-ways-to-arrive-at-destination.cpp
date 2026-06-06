class Solution {
public:
    const int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &r: roads){
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }
        vector<long long>dist(n, LLONG_MAX);
        vector<long long>ways(n, 0);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>pq;

        pq.push({0,0});
        dist[0] = 0;
        ways[0] = 1;

        while(!pq.empty()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(dis > dist[node]) continue;

            for(auto &nbr: adj[node]){
                int adjnode = nbr.first;
                long long edg = nbr.second;

                if(dis+edg < dist[adjnode]){
                    dist[adjnode] = dis+edg;
                    ways[adjnode] = ways[node];
                    pq.push({dist[adjnode], adjnode});
                }
                else if(dis + edg == dist[adjnode]){
                    ways[adjnode] = (ways[adjnode] + ways[node])%mod;
                }

            } 
        }
        return ways[n-1]%mod;
    }
};