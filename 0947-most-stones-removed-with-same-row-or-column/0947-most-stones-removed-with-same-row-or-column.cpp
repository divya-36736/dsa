class distjointset{
    public:
       vector<int>parent;
       vector<int>rank;
       distjointset(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int findupar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findupar(parent[node]);
    }

    void unionByrank(int u, int v){
        int ulpa_u = findupar(u);
        int ulpa_v = findupar(v);

        if(ulpa_u == ulpa_v) return;
        if(rank[ulpa_u]>rank[ulpa_v]){
            parent[ulpa_v] = ulpa_u;
            rank[ulpa_u]++;
        }
        else if(rank[ulpa_v]>rank[ulpa_u]){
            parent[ulpa_u] = ulpa_v;
            rank[ulpa_v]++;
        }else{
            parent[ulpa_u] = ulpa_v;
            rank[ulpa_u]++;
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        distjointset ds(n);
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    ds.unionByrank(i, j);
                }
            }
        }
        int comp = 0;
        for(int i=0; i<n; i++){
            if(ds.findupar(i) == i) comp++;
        }
        return n-comp;
    }
};