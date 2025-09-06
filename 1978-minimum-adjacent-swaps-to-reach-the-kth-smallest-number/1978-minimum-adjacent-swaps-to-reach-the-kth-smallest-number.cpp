class Solution {
public:
    void nextPermutation(string &s) {
        int n = s.size();
        int i = n - 2;
        while (i >= 0 && s[i] >= s[i + 1]) i--;
        if (i >= 0) {
            int j = n - 1;
            while (s[j] <= s[i]) j--;
            swap(s[i], s[j]);
        }
        reverse(s.begin() + i + 1, s.end());
    }

    int getMinSwaps(string num, int k) {
        string target = num;
        for (int i = 0; i < k; i++) {
            nextPermutation(target);
        }

        int n = num.size();
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (num[i] == target[i]) continue;

            // find position of target[i] in num (starting from i+1)
            int j = i + 1;
            while (num[j] != target[i]) j++;

            // bubble num[j] leftwards to position i
            while (j > i) {
                swap(num[j], num[j - 1]);
                swaps++;
                j--;
            }
        }

        return swaps;
    }
};
