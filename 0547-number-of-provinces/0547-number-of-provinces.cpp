class Solution {
public:
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

            if(rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }

            else{
                parent[ulp_v] = parent[ulp_u];
                rank[ulp_u]++;
            }
        } 
    };
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        //i want to it DSU 
        //i this we find the ultimate parent if the parent same then the connected other wise not

        DisjointSet ds(n);

        for(int i = 0; i<n; i++){
            for(int j= i+1; j<n; j++){
                if(isConnected[i][j] == 1){
                    ds.unionByRank(i, j);
                }
            }
        }
        int pro = 0;
        for(int i = 0; i<n; i++){
            if(ds.findUpar(i) == i) pro++;
        }
        return pro;
    }
};