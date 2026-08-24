class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        int cntNode = 0;
        int ans = 0;
        queue<int> q;
        vector<vector<int>> t(n, vector<int>(26, 0));

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                t[i][colors[i] - 'a'] = 1;
            }
        }
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            cntNode++;

            ans = max(ans, t[u][colors[u] - 'a']);

            for (auto& v : adj[u]) {
                for (int i = 0; i < 26; i++) {
                    t[v][i] = max(t[v][i], t[u][i] + (i == colors[v] - 'a'));
                }
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }
        if (cntNode < n)
            return -1;
        return ans;
    }
};