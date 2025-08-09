class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);
        for (int i = 0; i < n; i++) {
            // if lower case aeiou
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                lower[s[i] - 'a']++;
                s[i] = '#';
            } else if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
                       s[i] == 'O' || s[i] == 'U') {
                upper[s[i] - 'A']++;
                s[i] = '#';
            }
        }
        string vowels;
        // string uper
        for (int i = 0; i < 26; i++) {
            // charracter
            char c = 'A' + i;
            // add kb tk honge
            while (upper[i]) {
                vowels += c;
                upper[i]--;
            }
        }
        // stirng lower
        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            // add kb tk honge
            while (lower[i]) {
                vowels += c;
                lower[i]--;
            }
        }
        int first = 0; //for s
        int second = 0; //for vowels
        while(second<vowels.size()){
            if(s[first] == '#'){
                s[first]=vowels[second];
                second++;
            }
            first++;
        }
        return s;
    }
};