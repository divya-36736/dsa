class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

        for(int i = 0; i<n; i++){
            pq.push({arr[i], i});
        }
        int rank = 0;
        vector<int>res(n);
        int prev= INT_MAX;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int fist = it.first;
            int scnd = it.second;

            if(prev != fist){
                prev = fist;
                rank++;
            }
            res[scnd] = rank;
        }
        return res;
    }
};