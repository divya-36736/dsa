class Solution {
public:
    bool dfs(int v, int dest, vector<bool>& visited, vector<vector<int>>& adj){
        if(v == dest){
            return true;
        }
        if(visited[v]){
            return false;
        }
        visited[v] = true;
        for(int w : adj[v]){
        if(dfs(w, dest, visited, adj)){
            return true;
        }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool>visited(n,false);
        return dfs(source, destination, visited,adj);
    }
};