class Solution {
public:
    int primsAlgo(vector<vector<pair<int,int>>>& adj, int V) {
    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;

    vector<int> vis(V,0);
    pq.push({0,0});   // {weight,node}

    int sum = 0;

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        int edg = it.first;
        int node = it.second;

        if(vis[node]) continue;

        vis[node] = 1;
        sum += edg;

        for(auto &adjnode : adj[node]){
            pq.push({adjnode.second, adjnode.first});
        }
    }
    return sum;
}
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                int d = abs(x1-x2)+abs(y1-y2);

                adj[i].push_back({j, d});
                adj[j].push_back({i, d});
            }
        }
        return primsAlgo(adj, n);
    }
};