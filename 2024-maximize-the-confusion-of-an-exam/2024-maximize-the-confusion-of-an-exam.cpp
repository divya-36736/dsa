class Solution {
public:
    int changes(string answerKey, int k, char target) {
        int n = answerKey.size();
        int left = 0;
        int cnt = 0;       // number of flips used
        int maxlen = 0;

        for (int right = 0; right < n; right++) {
            if (answerKey[right] != target) {
                cnt++;    // need to flip this
            }

            while (cnt > k) {
                if (answerKey[left] != target) {
                    cnt--;
                }
                left++;
            }

            maxlen = max(maxlen, right - left + 1);
        }

        return maxlen;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(
            changes(answerKey, k, 'T'),
            changes(answerKey, k, 'F')
        );
    }
};
