class DisjointSet{
    public:
       vector<int>parent;
       vector<int>rank;

       DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);

        for(int i = 0; i<=n; i++){
            parent[i] = i;
        }
       }

       int findUpar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUpar(parent[node]);
       }

       void unionByRank(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
       }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        DisjointSet ds(n);

        for(auto &e: edges){
            int node1 = e[0];
            int node2 = e[1];
            if(ds.findUpar(node1) == ds.findUpar(node2)) return e;
            ds.unionByRank(node1, node2);
        }
        return {};
    }
};