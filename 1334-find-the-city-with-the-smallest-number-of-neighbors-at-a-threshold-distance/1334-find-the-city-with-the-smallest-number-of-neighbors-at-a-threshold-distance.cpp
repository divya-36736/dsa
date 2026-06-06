class Solution {
public:
    int findTheCity(int n,
                    vector<vector<int>>& edges,
                    int distanceThreshold) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        int cityNo = -1;
        int minCnt = INT_MAX;

        for(int src = 0; src < n; src++){

            vector<int> dist(n, 1e9);

            priority_queue<
                pair<int,int>,
                vector<pair<int,int>>,
                greater<pair<int,int>>
            > pq;

            dist[src] = 0;
            pq.push({0, src});

            while(!pq.empty()){

                auto [dis, node] = pq.top();
                pq.pop();

                if(dis > dist[node]) continue;

                for(auto &nbr : adj[node]){

                    int adjNode = nbr.first;
                    int wt = nbr.second;

                    if(dis + wt < dist[adjNode]){

                        dist[adjNode] = dis + wt;

                        pq.push({
                            dist[adjNode],
                            adjNode
                        });
                    }
                }
            }

            int cnt = 0;

            for(int i = 0; i < n; i++){

                if(dist[i] <= distanceThreshold)
                    cnt++;
            }

            if(cnt <= minCnt){
                minCnt = cnt;
                cityNo = src;
            }
        }

        return cityNo;
    }
};