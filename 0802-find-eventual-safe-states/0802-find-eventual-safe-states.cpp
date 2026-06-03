class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();

        vector<int>adj[n];
        vector<int>ind(n, 0);

        for(int i = 0; i<n; i++){
            for(auto &it: graph[i]){
                adj[it].push_back(i);
                ind[i]++;
            }
        }

        queue<int>q;

        for(int i = 0; i<n; i++){
            if(ind[i] == 0){
                q.push(i);
            }
        }

        vector<int>safe;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            safe.push_back(node);
            for(auto &nbr: adj[node]){
                ind[nbr]--;
                if(ind[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        sort(safe.begin(), safe.end());
        return safe;
    }
};