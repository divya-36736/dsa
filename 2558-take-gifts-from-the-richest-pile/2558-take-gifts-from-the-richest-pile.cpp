class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();

        priority_queue<long long> pq;
        for (int i = 0; i < n; i++) {
            pq.push(gifts[i]);
        }

        while (k > 0) {
            long long topElement = pq.top();
            pq.pop();

            topElement = sqrt(topElement);
            pq.push(topElement);
            k--;
        }

        long long sum = 0;  // int to long long
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};
