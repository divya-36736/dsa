class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>>adj[n];
        for(auto e: flights){
            int s = e[0];
            int d = e[1];
            int wt = e[2];
            adj[s].push_back({d, wt});
        }

        vector<int>dist(n, 1e9);
        dist[src] = 0;

        queue<pair<int,pair<int, int>>>q;
        q.push({src, {dist[src], 0}});


        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int s = it.first;
            int d = it.second.first;
            int stops = it.second.second;

            if(stops>k) continue;

            for(auto &nbr: adj[s]){
                int nbr1 = nbr.first;
                int cost = nbr.second;

                if(cost + d < dist[nbr1] && stops<=k){
                    dist[nbr1] = cost+d;
                    q.push({nbr1, {dist[nbr1], stops+1}});

                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};