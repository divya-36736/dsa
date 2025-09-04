class Solution {
public:
    vector<string> result;

    void backtrack(string &num, int target, int index, long long value, long long prev, string expr) {
        if (index == num.size()) {
            if (value == target) result.push_back(expr);
            return;
        }

        for (int i = index; i < num.size(); i++) {
            // Prevent numbers with leading zero
            if (i > index && num[index] == '0') break;

            string currStr = num.substr(index, i - index + 1);
            long long curr = stoll(currStr);

            if (index == 0) {
                // First number, take as is
                backtrack(num, target, i + 1, curr, curr, currStr);
            } else {
                // '+'
                backtrack(num, target, i + 1, value + curr, curr, expr + "+" + currStr);

                // '-'
                backtrack(num, target, i + 1, value - curr, -curr, expr + "-" + currStr);

                // '*'
                backtrack(num, target, i + 1, value - prev + prev * curr, prev * curr, expr + "*" + currStr);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        backtrack(num, target, 0, 0, 0, "");
        return result;
    }
};
