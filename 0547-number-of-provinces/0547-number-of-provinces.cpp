class Solution {
public:
    void bfs(int st, vector<vector<int>>& isConnected, vector<int>&vis){
        int n = isConnected.size();
        
        queue<int>q;

        vis[st] = 1;
        q.push(st);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int i = 0; i<n; i++){
                if(isConnected[node][i] == 1 && !vis[i]){
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int  cnt = 0;
        vector<int>vis(n, 0);
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                
                bfs(i, isConnected, vis);
                cnt++;
            }
        }
        return cnt;
    }
};