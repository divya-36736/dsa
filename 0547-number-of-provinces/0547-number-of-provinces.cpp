class Solution {
public:

    void bfs(int node, vector<vector<int>>& adj, vector<int>& visited) {

        queue<int> q;
        q.push(node);
        visited[node] = 1;

        while(!q.empty()) {

            int nodes = q.front();
            q.pop();

            for(auto &nbr : adj[nodes]) {

                if(!visited[nbr]) {

                    visited[nbr] = 1;
                    q.push(nbr);
                }
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
                bfs(i, adj, visited);
            }
        }

        return cnt;
    }
};