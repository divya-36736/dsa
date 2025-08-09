class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans(10);
        //make string for per word check
        string temp;
        //cnt for total num of words
        int cnt = 0;
        int idx = 0;
        while (idx < s.size()) {
            if (s[idx] == ' ') {
                //check the last number of temp ki voh konsi pos pr voh word aaega
                int pos = temp[temp.size() - 1] - '0';
                //after checking the pos hum temp se pos ko pop kre dende
                temp.pop_back();
                //ans me us temp ko dal diya
                ans[pos-1] = temp;
                //phitr temp ko clear kiya for next word 
                temp.clear();
                cnt++;
                idx++;
            } else {
                //if khali space nhi hai toh temp ko add krte jao
                temp += s[idx];
                idx++;
            }
        }
        //last wale word temp me hoga uska bhi toh number check krna padega and temp ko clear hbi and usko ams me bhi set krna padega
        int pos = temp[temp.size() - 1] - '0';
        temp.pop_back();
        ans[pos-1] = temp;
        temp.clear();
        cnt++;
        //us cnt tk hum iteratekarvanege , ki hamare kitne words the
        for(int i = 0; i<cnt; i++){
            temp += ans[i];
            temp += ' ';
        }
        //last me space hogi usko bhi pop krbvana padega
        temp.pop_back();
        return temp;
    }
};