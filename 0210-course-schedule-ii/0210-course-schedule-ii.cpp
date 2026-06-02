class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>adj(n);
        for(auto edge: prerequisites){
            int u = edge[0];
            int v = edge[1];
            adj[v].push_back(u);
        }

        vector<int>indegree(n, 0);
        for(int i = 0; i<n; i++){
            for(auto &it: adj[i]){
                indegree[it]++;
            }
        }

        queue<int>q;
        for(int i = 0; i<n; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int>ans;
        int cnt = 0;

        while(!q.empty()){
            int it = q.front();
            ans.push_back(it);
            q.pop();
            cnt++;
            for(auto &nbr: adj[it]){
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }
        return ans;
    }
};