class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int cntopen = 0;
        int cntclose = 0;
        for(char &c:s){
            if(c == '('){
                cntopen++;
            }else{
                if(cntopen>0){
                    cntopen--;
                }else{
                    cntclose++;
                }
            }
        }
        return cntopen+cntclose;
    }
};