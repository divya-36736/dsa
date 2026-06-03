class Solution {
public:
    vector<int>topo(int k, vector<vector<int>>&conditions){
        vector<vector<int>>adj(k+1);
        vector<int>ind(k+1, 0);

        for(int i = 0; i<k; i++){
            for(auto &it: conditions){
                adj[it[0]].push_back(it[1]);
                ind[it[1]]++;
            }
        }

        queue<int>q;
        for(int i = 1; i<=k; i++){
            if(ind[i] == 0){
                q.push(i);
            }
        }

        vector<int>order;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            order.push_back(node);

            for(auto nbr: adj[node]){
                ind[nbr]--;
                if(ind[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        if(order.size() != k) return {};
        return order;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>rowOrder = topo(k, rowConditions);
        vector<int>colOrder = topo(k, colConditions);

        if(rowOrder.empty() || colOrder.empty()) return {};

        vector<int>rowPos(k+1, 0), colPos(k+1, 0);
        for(int i = 0; i<k; i++){
            rowPos[rowOrder[i]] = i;
            colPos[colOrder[i]] = i;
        }

        vector<vector<int>>ans(k, vector<int>(k, 0));

        for(int i = 1; i<=k; i++){
            ans[rowPos[i]][colPos[i]] = i;
        }
        return ans;
    }
};