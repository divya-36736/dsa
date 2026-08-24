class Solution {
public:
    void dfs(vector<int>&edges, int node, vector<int>&dist, vector<int>&vis){
        vis[node] = 1;

        int v = edges[node];
        if(v != -1 && !vis[v]){
            vis[v] = 1;
            dist[v] = 1+dist[node];
            dfs(edges, v, dist, vis);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int>dist1(n, INT_MAX);
        vector<int>dist2(n, INT_MAX);

        vector<int>vis1(n, 0);
        vector<int>vis2(n, 0);

        dist1[node1] = 0;
        dist2[node2] = 0;

        dfs(edges, node1, dist1, vis1);
        dfs(edges, node2, dist2, vis2);

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