class Solution {
public:
    int convert(char c){
        
        if(c == 'I') return 1;
        else if(c == 'X') return 10;
        else if(c == 'V') return 5;
        else if(c == 'L') return 50;
        else if(c == 'C') return 100;
        else if(c == 'D') return 500;
        else return 1000;
    };
    int romanToInt(string s) {
        int sum = 0;
        int n = s.size();
        for(int i = 0; i<n-1; i++){
            if(convert(s[i]) < convert(s[i+1])){
                //-hoga
                sum -= convert(s[i]);
            }
            else{
                sum += convert(s[i]);
            }
        }
        sum += convert(s[n-1]);
        return sum;
    }
};