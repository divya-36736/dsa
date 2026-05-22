class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) return true; 
        vector<vector<int>>adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        bool find = false;
        vector<int>visited(n, 0);
        queue<int>q;
        q.push(source);
        visited[source] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &nbr: adj[node]){
                if(nbr == destination){
                    return true;
                }
                if(!visited[nbr]){
                    visited[nbr] = 1;
                    q.push(nbr);
                }
            }
        }
        return false;
    }
};