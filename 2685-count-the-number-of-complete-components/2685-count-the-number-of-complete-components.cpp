class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<int> adj[n];

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> visited(n, 0);

        int cnt = 0;

        for (int i = 0; i < n; i++) {

            if (visited[i]) continue;

            int nodes = 0;
            int degreesum = 0;

            queue<int> q;
            q.push(i);
            visited[i] = 1;

            while (!q.empty()) {

                int node = q.front();
                q.pop();

                nodes++;

                degreesum += adj[node].size();

                for (auto &nbr : adj[node]) {
                    if (!visited[nbr]) {
                        visited[nbr] = 1;
                        q.push(nbr);
                    }
                }
            }

            int edgescount = degreesum / 2;

            if (edgescount == nodes * (nodes - 1) / 2) {
                cnt++;
            }
        }

        return cnt;
    }
};