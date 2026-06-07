class DisjointSet{
    public:
      vector<int>parent;
      vector<int>rank;

      DisjointSet(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i<n; i++){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(m < n-1) return -1;

        DisjointSet ds(n);

        for(auto &e: connections){
            ds.unionByRank(e[0], e[1]);
        }

        unordered_set<int>comp;
        for(int i = 0; i<n; i++){
            comp.insert(ds.findUpar(i));
        }
        return comp.size()-1;
    }
};