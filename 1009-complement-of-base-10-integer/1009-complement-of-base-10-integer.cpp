class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        string binary = "";
        while(n>0){
            binary += (n%2) + '0';
            n /= 2;
        }
        reverse(binary.begin(), binary.end());
        //complement
        for(char &c: binary){
            if(c == '0') c = '1';
            else c = '0';
        }
        // convert back to decimal
        int ans = 0;
        for(char &c : binary){
            ans = ans * 2 + (c - '0');
        }

        return ans;
    }
};