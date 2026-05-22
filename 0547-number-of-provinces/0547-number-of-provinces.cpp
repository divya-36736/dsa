class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;
        for(int j = 0; j<adj[node].size(); j++){
            if(!visited[adj[node][j]]){
                dfs(adj[node][j], adj, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                if(i != j && isConnected[i][j] == 1) {

                    adj[i].push_back(j);
                }
            }
        }

        int cnt = 0;
        vector<int> visited(n, 0);

        for(int i = 0; i < n; i++) {

            if(!visited[i]) {

                cnt++;
                dfs(i, adj, visited);
            }
        }

        return cnt;
    }
};