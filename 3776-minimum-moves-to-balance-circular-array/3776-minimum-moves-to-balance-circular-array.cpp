class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n = balance.size();
        int idx = -1;

        // find the negative index
        for (int i = 0; i < n; i++) {
            if (balance[i] < 0) {
                idx = i;
                break;
            }
        }

        // no negative balance
        if (idx == -1) return 0;

        long long need = -balance[idx];
        long long total = 0;
        for (int x : balance) total += x;

        // impossible
        if (total < 0) return -1;

        long long moves = 0;
        int dist = 1;

        // expand outward in circular manner
        while (need > 0) {
            int left = (idx - dist + n) % n;
            int right = (idx + dist) % n;

            if (balance[left] > 0) {
                long long take = min((long long)balance[left], need);
                moves += take * dist;
                need -= take;
                balance[left] -= take;
            }

            if (need > 0 && balance[right] > 0) {
                long long take = min((long long)balance[right], need);
                moves += take * dist;
                need -= take;
                balance[right] -= take;
            }

            dist++;

            // safety (should never happen logically)
            if (dist > n) return -1;
        }

        return moves;
    }
};
