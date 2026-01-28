class Solution {
public:
    int change(string answerKey, int k, char c){
        int l = 0;
        int cnt = 0;
        int maxlen = 0;
        for(int r = 0; r<answerKey.size(); r++){
            if(answerKey[r] != c){
                cnt++; //need to change
            }
            while(cnt > k){
                if(answerKey[l] != c){
                    cnt--;
                }
                l++;
            }
            maxlen = max(maxlen, r-l+1);
        }
        return maxlen;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(change(answerKey, k, 'T'), change(answerKey, k, 'F'));
    }
};