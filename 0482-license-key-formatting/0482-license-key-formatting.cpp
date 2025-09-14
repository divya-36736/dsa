class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string temp = "";
        // 1. Remove dashes and convert to uppercase
        for(char c : s) {
            if(c != '-') {
                temp += toupper(c);
            }
        }
        
        int n = temp.size();
        string result = "";
        
        // 2. Determine size of first group
        int firstGroup = n % k;
        if(firstGroup == 0) firstGroup = k;
        
        // 3. Add first group
        result = temp.substr(0, firstGroup);
        
        // 4. Add remaining groups
        for(int i = firstGroup; i < n; i += k) {
            result += "-";
            result += temp.substr(i, k);
        }
        
        return result;
    }
};
