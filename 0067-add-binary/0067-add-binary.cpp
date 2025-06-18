class Solution {
public:
    string addBinary(string a, string b) {
        int a1 = a.size()-1;
        int b1 = b.size()-1;
        string res = "";
        int carry = 0;
        while(a1 >= 0 || b1 >= 0 || carry){
            int sum = carry;
            if(a1 >= 0) sum += a[a1--]-'0';
            if(b1 >= 0) sum += b[b1--]-'0';
            
            res = char(sum%2 + '0')+ res;
            carry = sum/2;
        }
        return res;
    }
};