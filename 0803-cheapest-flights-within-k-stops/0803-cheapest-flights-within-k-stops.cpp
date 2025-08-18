class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //1st we will create graph
        vector<pair<int, int>>adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        //make queue for stores stops,{ node, dst};
        queue<pair<int, pair<int, int>>>q;
        //hamane initial stops ko and initial node and 
        //dst ko queue me push kiya  
        q.push({0, {src, 0}});
        //hamane ek distance vector bamaya jise 
        //hamen inifite se inititate kiya
        vector<int>dist(n, 1e9);
        //initial dist[src] = 0
        dist[src] = 0;
        //yha hamane dijkstra chalai hai
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops>k) continue;
            for(auto iter : adj[node]){
                int adjNode = iter.first;//node
                int edw = iter.second; //edges weight

                if(cost+edw < dist[adjNode] && stops <= k){
                    dist[adjNode] = cost+edw;
                    q.push({stops+1, {adjNode, cost+edw}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};