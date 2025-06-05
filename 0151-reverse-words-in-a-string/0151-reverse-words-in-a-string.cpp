class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        // reverse(s.begin(), s.end());
        // string ans = "";
        // for (int i = 0; i < n; i++) {
        //     string word = "";
        //     while (i < n && s[i] != ' ') {
        //         word += s[i];
        //         i++;
        //     }
        //     reverse(word.begin(), word.end());
        //     if (!word.empty()) {
        //         if (!ans.empty())
        //             ans += " ";
        //         ans += word;
        //     }
        // }
        // return ans;

        string temp = "";
        string ans = "";
        int left = 0;
        int right = n-1;
        while(left <= right){
            char ch = s[left];
            if(ch != ' '){
                temp += ch;
            }else if (ch == ' ' && !temp.empty()) {
                if (ans!="") ans = temp + " " + ans;
                else ans = temp;
                temp = "";
        }
        left++;
        }
        if (temp!="") {
            if (ans!="") ans = temp + " " + ans;
            else ans = temp;
    }
    
    return ans;    
    }
};
