class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";

        for (int i = 2; i < num.size(); i++) {
            if (num[i] == num[i-1] && num[i] == num[i-2]) {
                string curr = "";
                curr += num[i-2];
                curr += num[i-1];
                curr += num[i];

                ans = max(ans, curr);
            }
        }
        return ans;
    }
};
