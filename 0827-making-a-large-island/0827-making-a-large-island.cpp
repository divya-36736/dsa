class DisjointSet {
public:
    vector<int> parent;
    vector<int> size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUpar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }

    void unionBysize(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        // int m = grid[0].size();

        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, -1, 0, 1};

        DisjointSet ds(n*n);

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {

                if (grid[row][col] == 0)
                    continue;

                for (int k = 0; k < 4; k++) {
                    int nr = row + dr[k];
                    int nc = col + dc[k];

                    if (nr >= 0 && nc >= 0 && nr < n && nc < n &&
                        grid[nr][nc] == 1) {
                        int u = row * n + col;
                        int v = nr * n + nc;
                        ds.unionBysize(u, v);
                    }
                }
            }
        }

        // detect zero
        int ans = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {

                if (grid[row][col] == 1)
                    continue;

                unordered_set<int> st;
                for (int k = 0; k < 4; k++) {
                    int nr = row + dr[k];
                    int nc = col + dc[k];

                    if (nr >= 0 && nc >= 0 && nr < n && nc < n &&
                        grid[nr][nc] == 1) {
                        st.insert(ds.findUpar(nr * n + nc));
                    }
                }
                int total = 1;
                for (auto parent : st) {
                    total += ds.size[parent];
                }
                ans = max(ans, total);
            }
        }

        for (int i = 0; i < n * n; i++) {
            ans = max(ans, ds.size[ds.findUpar(i)]);
        }
        return ans;
    }
};