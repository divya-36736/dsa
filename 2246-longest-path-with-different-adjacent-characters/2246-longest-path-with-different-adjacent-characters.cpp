class Solution {
public:
    int ans = 1;
    int dfs(int node, vector<vector<int>>& adj, string& s) {
        int best1 = 0, best2 = 0;

        for (int child : adj[node]) {
            int len = dfs(child, adj, s);

            if (s[child] == s[node])
                continue;

            if (len > best1) {
                best2 = best1;
                best1 = len;
            }
            else if (len > best2) {
                best2 = len;
            }
        }

        ans = max(ans, best1 + best2 + 1);
        return best1 + 1;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        dfs(0, adj, s);
        return ans;
    }
};