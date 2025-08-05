class Solution {
public:
    // bool check(int i, string s){
    //     int n = s.length();
    //     //base case
    //     if(i>=s.length()-1) return true;
    //     //check
    //     if(tolower(s[i]) != tolower(s[n-i-1])){
    //         return false;
    //     }
    //     return check(i+1, s);
    // }
    bool isPalindrome(string s) {
        // return check(0, s);
        int left = 0, right = s.length()-1;
        while(left<right)
        {
            if(!isalnum(s[left])) 
                left++;
            else if(!isalnum(s[right])) 
                right--;
            else if(tolower(s[left])!=tolower(s[right])) 
                return false;
            else {
                left++; 
                right--;
            }
        }
        return true;

    }
};