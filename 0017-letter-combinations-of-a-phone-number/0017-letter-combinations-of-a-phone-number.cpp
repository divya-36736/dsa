class Solution {
public:
    void phone(int index, vector<string>& ans, string digits, string output, string mapping[]) {
        // Base case
        if(index == digits.size()) {
            ans.push_back(output);
            return;
        }
        
        // Convert character to integer (e.g. '2' -> 2)
        int number = digits[index] - '0';
        string value = mapping[number];

        for(int j = 0; j < value.size(); j++) {
            output.push_back(value[j]);
            phone(index + 1, ans, digits, output, mapping);
            output.pop_back(); // backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) return ans;
        
        string output = "";
        string mapping[10] = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        phone(0, ans, digits, output, mapping);
        return ans;
    }
};
