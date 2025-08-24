class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        //we do priority queue bcz isme deletion insertion ho rha hai
        //1st we make priority queue
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            pq.push(stones[i]);
        }
        while (pq.size() > 1) {
            int wt = pq.top(); 
            pq.pop();                 // heaviest nikala

            int second = pq.top(); 
            pq.pop();                 //second heaviest bhi nikalo

            wt -= second;             // difference
            if (wt) pq.push(wt);      // agar bacha to wapas daalo
        }
        return pq.empty() ? 0 : pq.top();
    }
};
