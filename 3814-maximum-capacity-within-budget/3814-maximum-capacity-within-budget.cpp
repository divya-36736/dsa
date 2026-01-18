class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();

        //store in vector and sort
        vector<pair<int, int>>store;
        for(int i = 0; i<n; i++){
            store.push_back({costs[i], capacity[i]});
        }
        //sort
        sort(store.begin(), store.end());
        //prefix max capacity
        vector<int>prefix(n);
        prefix[0] = store[0].second;
        for(int i = 1; i<n; i++){
            prefix[i] = max(prefix[i-1], store[i].second);
        }

        int ans = 0;
        int j = n-1;
        //two pointer
        for(int i = 0; i<n; i++){
            int cost_i = store[i].first;
            int cap_i = store[i].second;
            // Single machine
            if(cost_i < budget){
                ans = max(ans, cap_i);
            }
            // Move j to satisfy strict budget
            while (j >= 0 && cost_i + store[j].first >= budget) {
                j--;
            }
             // Ensure distinct machines
            int k = min(j, i - 1);
            if (k >= 0) {
                ans = max(ans, cap_i + prefix[k]);
            }
        }
        return ans;
    }
};