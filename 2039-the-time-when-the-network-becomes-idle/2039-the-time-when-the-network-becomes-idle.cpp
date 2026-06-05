class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {

        int n = patience.size();

        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> dist(n, -1);

        queue<int> q;
        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto &nbr : adj[node]) {
                if (dist[nbr] == -1) {
                    dist[nbr] = dist[node] + 1;
                    q.push(nbr);
                }
            }
        }

        long long lastTime = 0;

        for (int i = 1; i < n; i++) {

            long long rt = 2LL * dist[i];   

            long long arrival;

            if (patience[i] >= rt) {
                arrival = rt;
            }
            else {
                long long lastResend =
                    ((rt - 1) / patience[i]) * 1LL * patience[i];

                arrival = lastResend + rt;
            }

            lastTime = max(lastTime, arrival);
        }

        return lastTime + 1;
    }
};