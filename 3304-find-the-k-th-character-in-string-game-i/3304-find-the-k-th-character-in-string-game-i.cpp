class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(s.size()<k){
            int n = s.size();
            string add = "";
            for (int i = 0 ; i <n ; i++){
                 add += s[i] + 1;
            }
            s += add ;
        }

        // Finding the kth character of the string 
        return s[k-1];
    }
};