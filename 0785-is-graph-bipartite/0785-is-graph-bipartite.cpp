class Solution {
public:
    bool dfs(int i, int col, vector<int>&color, vector<vector<int>>&graph){
        color[i] = col;

        for(auto nbr:graph[i]){
            if(color[nbr] == -1){
                if(dfs(nbr, !col, color, graph) == false) return false;
            }
            if(color[nbr] == col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>color(v, -1);
        for(int i =0; i<v; i++){
            if(color[i] == -1){
                if(dfs(i, 0, color, graph) == false) return false;
            }
        }
        return true;
    }
};