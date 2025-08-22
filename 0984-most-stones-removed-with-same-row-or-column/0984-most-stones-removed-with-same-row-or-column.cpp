class DisjointSet{
    vector<int>parent, size, rank;
    public:
       DisjointSet(int n) {
       rank.resize(n+1, 0);
       parent.resize(n+1);
       size.resize(n+1);

       for(int i=0; i<=n; i++){
        parent[i] = i; //initially own node is own parent
        size[i] = 1; //initially size = 1
       }
    }

    //find upper parent
    int findUPar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v){
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v); 

    if(ulp_u == ulp_v) return;

    if(size[ulp_u] < size[ulp_v]){
        parent[ulp_u] = ulp_v;
        size[ulp_v] += size[ulp_u];
    } 
    else {
        parent[ulp_v] = ulp_u;
        size[ulp_u] += size[ulp_v];
    }
}

};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxrow = 0;
        int maxcol = 0;
        for(auto it: stones){
            maxrow = max(maxrow, it[0]);
            maxcol = max(maxcol, it[1]);
        }
        DisjointSet ds(maxrow + maxcol + 1);
        unordered_map<int, int>stoneNode;
        for(auto it: stones){
            int noderow = it[0];
            int nodecol = it[1] + maxrow + 1;
            ds.unionBySize(noderow, nodecol);
            stoneNode[noderow] = 1;
            stoneNode[nodecol] = 1;
        }
        int cnt = 0;
        for(auto it: stoneNode){
            if(ds.findUPar(it.first) == it.first){
                cnt++;
            }
        }
        return (int)stones.size() - cnt;
    }
};