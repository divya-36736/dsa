class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>>adj[n+1];
        for(auto it:times){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
        }

        vector<int>dist(n+1, 1e9);
        dist[k] = 0;

        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({k, dist[k]});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int src = it.first;
            int dis = it.second;
            

            for(auto &nbr: adj[src]){
                int nbr1 = nbr.first;
                int cost = nbr.second;

                if(cost + dis < dist[nbr1]){
                    dist[nbr1] = cost + dis;
                    pq.push({nbr1, dist[nbr1]});
                }
            }
        }
        int maxi = 0;
        for(int i = 1; i<=n; i++){
            if(dist[i] == 1e9) return -1;
            else{
                maxi = max(maxi, dist[i]);
            }
        }
        return maxi;
    }
};