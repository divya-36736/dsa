class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //adjlist
        vector<vector<int>> adj(numCourses);
        for(auto &edge: prerequisites){
            int u = edge[0];
            int v = edge[1];
            adj[v].push_back(u);
        }

        
        vector<int>indegree(numCourses, 0);
        for(int i = 0; i<numCourses; i++){
            for(auto &it: adj[i]){
                indegree[it]++;
            }
        }

        
        queue<int>q;

        for(int i = 0; i<numCourses; i++){
            if(indegree[i] == 0) q.push(i);
            }
        

        int cnt = 0;

        while(!q.empty()){
            int it = q.front();
            q.pop();
            cnt++;
            for(auto &nbr: adj[it]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }

        return cnt == numCourses;

    }
};