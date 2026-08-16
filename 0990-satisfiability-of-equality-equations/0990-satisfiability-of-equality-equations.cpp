class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DisjointSet ds(26);

        for (string &s : equations) {
            if (s[1] == '=') {
                ds.unionByRank(s[0] - 'a', s[3] - 'a');
            }
        }

        for (string &s : equations) {
            if (s[1] == '!') {
                if (ds.findParent(s[0] - 'a') == ds.findParent(s[3] - 'a'))
                    return false;
            }
        }

        return true;
    }
};