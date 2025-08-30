// if continous increasing aur decreasing order me ahi toh
// uska return 1 hoga uska chunks 1 hoga aur
// jis arra me maxima ya minima hoga usme
// 1. maxima wale me joh maximum hai usko right side splite krenge
// 2. minimmum wale me joh left side hai uski teraf bhej kr sort k
// and ume bhi joh continus increasing or decreasing hai usko
//  bhi split kkrenge

class Solution {
public: 
    // strictly increasing?
    bool incr(vector<int>& arr) {
        for (int i = 1; i < (int)arr.size(); i++) {
            if (arr[i] <= arr[i-1]) return false;
        }
        return true;
    }

    // strictly decreasing?
    bool dcr(vector<int>& arr) {
        for (int i = 1; i < (int)arr.size(); i++) {
            if (arr[i] >= arr[i-1]) return false;
        }
        return true;
    }

    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        if (n == 1) return 1;

        // Agar pura strictly increasing hai -> har jagah cut possible -> n chunks.
        if (incr(arr)) return n;
        // Agar pura strictly decreasing hai -> koi valid cut nahi -> 1 chunk.
        if (dcr(arr)) return 1;

        // ✅ True-valid boundary check ke liye minRight banate hain
        vector<int> minRight(n + 1, INT_MAX);
        for (int i = n - 1; i >= 0; --i) {
            minRight[i] = min(arr[i], minRight[i + 1]);
        }

        int chunks = 0;
        int maxLeft = INT_MIN;

        for (int i = 0; i < n; i++) {
            maxLeft = max(maxLeft, arr[i]);

            // yahi REAL condition hai cut karne ki
            if (maxLeft <= minRight[i + 1]) {
                chunks++;
            }
        }
        return chunks;
    }
};
