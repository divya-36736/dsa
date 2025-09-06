#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMinSwaps(string num, int k) {
        string target = num;

        // generate kth next permutation directly using STL
        while (k--) {
            next_permutation(target.begin(), target.end());
        }

        int n = num.size();
        int swaps = 0;

        // count minimum adjacent swaps
        for (int i = 0; i < n; i++) {
            if (num[i] == target[i]) continue;

            int j = i + 1;
            while (num[j] != target[i]) j++;

            while (j > i) {
                swap(num[j], num[j - 1]);
                swaps++;
                j--;
            }
        }
        return swaps;
    }
};
