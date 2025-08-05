class Solution {
public:
    bool check(int i, string& clean){
        //base case
        int n = clean.size();
        if(i >= n/2) return true;
        //check
        if(tolower(clean[i]) !=tolower(clean[n-i-1])) return false;
        //recursive call
        return check(i+1, clean);
    }
    bool isPalindrome(string s) {
        string clean = "";
        for(char c: s){
            if(isalnum(c)){
                clean += c;
            }
        }
        // int left = 0, right = s.length()-1;
        // while(left<right)
        // {
        //     if(!isalnum(s[left])) 
        //         left++;
        //     else if(!isalnum(s[right])) 
        //         right--;
        //     else if(tolower(s[left])!=tolower(s[right])) 
        //         return false;
        //     else {
        //         left++; 
        //         right--;
        //     }
        // }
        // return true;

        return check(0, clean);
    }
};