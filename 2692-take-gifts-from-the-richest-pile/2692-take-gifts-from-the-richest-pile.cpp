class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        priority_queue<int>pq;

        for(int i = 0; i<n; i++){
            pq.push(gifts[i]);
        }
        while(k>0 && !pq.empty()){
            long long gift = pq.top();
            pq.pop();
            k--;
            int root = sqrt(gift);
            pq.push(root);
        }
        long long sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};