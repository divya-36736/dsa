class Solution {
public:
    // here we consider num1 >= num2
    string add(string &num1, string &num2) {
        int idx1 = num1.size() - 1;
        int idx2 = num2.size() - 1;
        int carry = 0, sum;
        string ans;

        while (idx2 >= 0) {
            sum = (num1[idx1] - '0') + (num2[idx2] - '0') + carry;
            carry = sum / 10;
            ans += char('0' + (sum % 10));
            idx1--, idx2--;
        }

        while (idx1 >= 0) {
            sum = (num1[idx1] - '0') + carry;
            carry = sum / 10;
            ans += char('0' + (sum % 10));
            idx1--;
        }

        if (carry) ans += '1';

        reverse(ans.begin(), ans.end());
        return ans;
    }

    string addStrings(string num1, string num2) {
        if (num2.size() > num1.size()) {
            return add(num2, num1);  // store result
        } else {
            return add(num1, num2);  // store result
        }
    }
};
