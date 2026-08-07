class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto &e:prerequisites){
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u);
        }
        int cnt = 0;
        vector<int>indegree(numCourses, 0);
        for(int i = 0; i<numCourses; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i = 0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int it = q.front();
            q.pop();
            cnt++;
            for(auto adjnode:adj[it]){
                indegree[adjnode]--;
                if(indegree[adjnode] ==0){
                    q.push(adjnode);
                }
            }
        }
        if(cnt == numCourses) return true;
        return false;
    }
};