class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>adj[n];
        vector<int>ind(n, 0);
        for(int i= 0; i<n; i++){
            for(int it:graph[i]){
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
            int it = q.front();
            q.pop();

            safe.push_back(it);
            for(auto adjnode:adj[it]){
                ind[adjnode]--;
                if(ind[adjnode] == 0){
                    q.push(adjnode);
                }
            }
        }
        sort(safe.begin(), safe.end());
        return safe;
    }
};