class Solution {
public:
    void bfs(vector<int>&edges, int node, vector<int>&dist){
        int n = edges.size();
        
        queue<int>q;
        dist[node] = 0;
        q.push(node);
        vector<int>vis(n, 0);
        vis[node] = 1;

        while(!q.empty()){
            int it = q.front();
            q.pop();

            int v = edges[it];
            if(v != -1 && !vis[v]){
                vis[v] = 1;
                dist[v] = 1+dist[it];
                q.push(v);
            }
        }

    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        vector<int>dist1(n, INT_MAX);
        vector<int>dist2(n, INT_MAX);

        bfs(edges, node1, dist1);
        bfs(edges, node2, dist2);

        int minNode = -1;
        int minDis = INT_MAX;
        for(int i = 0; i<n; i++){
            int maxDis = max(dist1[i], dist2[i]);
            if(minDis > maxDis){
                minDis = maxDis;
                minNode = i;
            }
        }
        return minNode;
    }
};