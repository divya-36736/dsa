class DisjointSet{
public:
    vector<int> parent, rank;

    DisjointSet(int n){
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++)
            parent[i]=i;
    }

    int findUpar(int node){
        if(parent[node]==node)
            return node;

        return parent[node]=findUpar(parent[node]);
    }

    void unionByRank(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);

        if(ulp_u==ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n=accounts.size();

        DisjointSet ds(n);

        unordered_map<string,int> mapMail;

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){

                string mail=accounts[i][j];

                if(mapMail.find(mail)==mapMail.end()){
                    mapMail[mail]=i;
                }
                else{
                    ds.unionByRank(i,mapMail[mail]);
                }
            }
        }

        vector<vector<string>> mergeMail(n);

        for(auto &it : mapMail){

            string mail=it.first;
            int node=ds.findUpar(it.second);

            mergeMail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i=0;i<n;i++){

            if(mergeMail[i].empty()) continue;

            sort(mergeMail[i].begin(), mergeMail[i].end());

            vector<string> temp;

            temp.push_back(accounts[i][0]);

            for(auto &mail : mergeMail[i]){
                temp.push_back(mail);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};