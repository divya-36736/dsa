class Solution {
public:
    double maxProbability(int n,
                          vector<vector<int>>& edges,
                          vector<double>& succProb,
                          int start_node,
                          int end_node) {

        vector<pair<int,double>> adj[n];

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];

            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        vector<double> pro(n, 0.0);

        priority_queue<pair<double,int>> pq;

        pro[start_node] = 1.0;
        pq.push({1.0, start_node});

        while(!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            double prob = it.first;
            int node = it.second;

            if(prob < pro[node]) continue;

            for(auto &nbr : adj[node]) {

                int adjnode = nbr.first;
                double edgprob = nbr.second;

                if(prob * edgprob > pro[adjnode]) {

                    pro[adjnode] = prob * edgprob;

                    pq.push({pro[adjnode], adjnode});
                }
            }
        }

        return pro[end_node];
    }
};