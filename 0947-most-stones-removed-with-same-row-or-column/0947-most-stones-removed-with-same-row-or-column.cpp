class DisjointSet{
    public:
      vector<int>parent;
      vector<int>size;

      DisjointSet(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
      }

      int findUpar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUpar(parent[node]);
      }

      void unionBysize(int u, int v){
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        DisjointSet ds(n);

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){

                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    ds.unionBysize(i, j);
                }
            }
        }

        int comp = 0;

        for(int i = 0; i<n; i++){
            if(ds.findUpar(i) == i) comp++;
        }

        return n-comp;

    }
};