class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        int i = 0;//for s;
        int j = 0;//for t
        while(i<n1 && j<n2){
            if(s[i] == t[j]){
                i++;

            }
            j++;
            
        }
        return i == n1;
    }
};
