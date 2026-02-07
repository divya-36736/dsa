class Solution {
public:
    vector<string> ones = {
        "", "One", "Two", "Three", "Four",
        "Five", "Six", "Seven", "Eight", "Nine"
    };

    vector<string> teens = {
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };

    vector<string> tens = {
        "", "", "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

    vector<string> thousands = {
        "", "Thousand", "Million", "Billion"
    };

    // Converts numbers less than 1000
    string helper(int num) {
        if (num == 0) return "";
        if (num < 10) return ones[num];
        if (num < 20) return teens[num - 10];
        if (num < 100) {
            return tens[num / 10] +
                   (num % 10 ? " " + ones[num % 10] : "");
        }
        return ones[num / 100] + " Hundred" +
               (num % 100 ? " " + helper(num % 100) : "");
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";

        string result;
        int i = 0;

        while (num > 0) {
            if (num % 1000 != 0) {
                string part = helper(num % 1000);
                if (!thousands[i].empty())
                    part += " " + thousands[i];

                result = part + (result.empty() ? "" : " " + result);
            }
            num /= 1000;
            i++;
        }
        return result;
    }
};
