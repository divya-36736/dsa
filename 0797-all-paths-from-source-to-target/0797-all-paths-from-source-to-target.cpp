class Solution {
public:
    void dfs(int node, vector<vector<int>>&graph, vector<vector<int>>&ans, vector<int>&path){
        int n = graph.size();

        path.push_back(node);

        if(node == n-1){
            ans.push_back(path);
            path.pop_back();
            return;
        }

        for(auto &nbr: graph[node]){
            dfs(nbr, graph, ans, path);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();

        vector<vector<int>>ans;
        vector<int>path;

        dfs(0, graph, ans, path);
        return ans;
    }
};