class DisjointSet{
    public:
      vector<int>parent;
      vector<int>size;

      DisjointSet(int n){
        parent.resize(n);
        size.resize(n, 0);
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
      }

      int findUpar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUpar(parent[node]);
      }

      void unionBySize(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }

        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
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
            ds.unionBySize(e[0], e[1]);
        }

        unordered_set<int>comp;
        for(int i = 0; i<n; i++){
            comp.insert(ds.findUpar(i));
        }
        return comp.size()-1;
    }
};